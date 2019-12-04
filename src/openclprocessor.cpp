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
    cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);
    cl_command_queue queue = clCreateCommandQueue(context, device, 0, NULL);

    char deviceName[1024];
    clGetDeviceInfo(device, CL_DEVICE_NAME, 1024, deviceName, NULL);
    cl_event event = NULL;

    //Read the source from the passed file
    std::string source = LoadSource();
    //We have to do this because opencl needs an address of a char * 
    const char *source_arr = source.c_str();

    //Compile the program
    cl_program program = clCreateProgramWithSource(context, 1, &source_arr, NULL, NULL);
    clBuildProgram(program, 0, NULL, "", NULL, NULL);


    //Read the output into a dynamically sized buffer.
    size_t log_size;
    clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
    char *c_message = (char*)malloc((log_size + 1) * sizeof(char));
    clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, log_size, c_message, NULL);
    c_message[log_size] = '\0';

    std::string compiler_message(c_message);

    free(c_message);

    if(compiler_message.length() > 10)
        throw "OpenCL compiler: " + compiler_message;

}


QState OpenCLProcessor::mul(const QState &m1, const QState &m2) {
    return DefaultProcessor::mul(m1, m2);
}

QState OpenCLProcessor::tensor(const QState &m1, const QState &m2) {
    return DefaultProcessor::tensor(m1, m2);
}
