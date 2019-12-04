#include "openclprocessor.h"

#include <CL/cl.h>

#include <iostream>
#include <fstream>

std::string OpenCLProcessor::LoadSource() {
    std::ifstream in(source_file_);

    if(!in)
        throw "Could not open OpenCL program file.";

    std::string program;

    std::string line;
    while(std::getline(in, line))
        program += line + "\n";

    return program;
}

OpenCLProcessor::OpenCLProcessor(std::string source_file) {
    this->source_file_ = source_file;

    //Initialize OpenCL
    //https://github.com/CNugteren/myGEMM/blob/master/extra/minimal.cpp
    cl_platform_id platform = 0;
    clGetPlatformIDs(1, &platform, NULL);

    cl_device_id device = 0;
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
    context_ = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);
    queue_ = clCreateCommandQueue(context_, device, 0, NULL);

    char deviceName[1024];
    clGetDeviceInfo(device, CL_DEVICE_NAME, 1024, deviceName, NULL);

    //Read the source from the passed file
    std::string source = LoadSource();
    //We have to do this because opencl needs an address of a char * 
    const char *source_arr = source.c_str();

    //Compile the program
    program_ = clCreateProgramWithSource(context_, 1, &source_arr, NULL, NULL);
    clBuildProgram(program_, 0, NULL, "", NULL, NULL);

    //Read the output into a dynamically sized buffer.
    size_t log_size;
    clGetProgramBuildInfo(program_, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
    char *c_message = (char*)malloc((log_size + 1) * sizeof(char));
    clGetProgramBuildInfo(program_, device, CL_PROGRAM_BUILD_LOG, log_size, c_message, NULL);
    c_message[log_size] = '\0';

    std::string compiler_message(c_message);

    free(c_message);

    if(compiler_message.length() > 10)
        throw "OpenCL compiler: " + compiler_message;

    //Load matrix multiplication kernel
    mult_kernel_ = clCreateKernel(program_, "mul_mat", NULL);
}


QState OpenCLProcessor::mul(const QState &m1, const QState &m2) {

    if(m1.get_cols() != m2.get_rows())
        throw "Dimension mismatch";

    const size_t num_rows = m1.get_rows();
    const size_t num_cols = m2.get_cols();
    const size_t num_elements = m1.get_cols();

    QState ret(num_rows, num_cols);

    //Create memory objects
    cl_mem m1_buf = clCreateBuffer(context_, CL_MEM_READ_ONLY,  num_rows * num_elements * sizeof(complex), NULL, NULL);
    cl_mem m2_buf = clCreateBuffer(context_, CL_MEM_READ_ONLY,  num_cols * num_elements * sizeof(complex), NULL, NULL);
    cl_mem ret_buf = clCreateBuffer(context_, CL_MEM_READ_WRITE, num_rows * num_cols * sizeof(complex), NULL, NULL);

    //Copy memory objects to gpu
    clEnqueueWriteBuffer(queue_, m1_buf, CL_TRUE, 0, num_rows * num_elements * sizeof(complex), m1[0], 0, NULL, NULL);
    clEnqueueWriteBuffer(queue_, m2_buf, CL_TRUE, 0, num_cols * num_elements * sizeof(complex), m2[0], 0, NULL, NULL);
    clEnqueueWriteBuffer(queue_, ret_buf, CL_TRUE, 0, num_rows * num_cols * sizeof(complex), ret[0], 0, NULL, NULL);

    //Write arguments to kernel
    clSetKernelArg(mult_kernel_, 0, sizeof(int), (void*)&num_rows);
    clSetKernelArg(mult_kernel_, 1, sizeof(int), (void*)&num_cols);
    clSetKernelArg(mult_kernel_, 2, sizeof(int), (void*)&num_elements);
    clSetKernelArg(mult_kernel_, 3, sizeof(cl_mem), (void*)&m1_buf);
    clSetKernelArg(mult_kernel_, 4, sizeof(cl_mem), (void*)&m2_buf);
    clSetKernelArg(mult_kernel_, 5, sizeof(cl_mem), (void*)&ret_buf);

    const size_t threadblock_width = num_rows > kThreadblockSize ? kThreadblockSize : num_rows;
    const size_t threadblock_height = num_cols > kThreadblockSize ? kThreadblockSize : num_cols;

    //Specify threadblock size thread ids
    const size_t local[2] = {threadblock_width, threadblock_height};
    const size_t global[2] = {num_rows, num_cols};

    //Execute kernel
    cl_event event = NULL;
    clEnqueueNDRangeKernel(queue_, mult_kernel_, 2, NULL, global, local, 0, NULL, &event);

    //Wait for kernel to finish
    clWaitForEvents(1, &event);

    //Copy from gpu to cpu
    clEnqueueReadBuffer(queue_, ret_buf, CL_TRUE, 0, num_rows * num_cols * sizeof(complex), ret[0], 0, NULL, NULL);

    //Cleanup
    clReleaseMemObject(m1_buf);
    clReleaseMemObject(m2_buf);
    clReleaseMemObject(ret_buf);

    return ret;
}

OpenCLProcessor::~OpenCLProcessor() {
    clReleaseCommandQueue(queue_);
    clReleaseContext(context_);
    clReleaseProgram(program_);
    clReleaseKernel(mult_kernel_);
}
