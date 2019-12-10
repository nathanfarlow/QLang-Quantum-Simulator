#pragma once

#include "defaultprocessor.h"
#include "../quantum/quantum.h"

#include <CL/cl.h>

using quantum::complex;
using quantum::QState;

constexpr int kThreadblockSize = 32;

class OpenCLProcessor : public DefaultProcessor<complex> {
private:
	std::string source_file_;

	cl_program program_;
	cl_command_queue queue_;
	cl_context context_;

	cl_kernel mult_kernel_;

	//Load the source from source_file_ as a string
	std::string LoadSource();
public:
	OpenCLProcessor(std::string source_file);
	virtual ~OpenCLProcessor();

    virtual QState mul(const QState &m1, const QState &m2);
};
