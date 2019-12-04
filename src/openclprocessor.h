#pragma once

#include "defaultprocessor.h"
#include "quantum.h"

using quantum::complex;
using quantum::QState;

class OpenCLProcessor : public DefaultProcessor<complex> {
private:
	std::string source_file_;

	//Load the source from source_file_ as a string
	std::string LoadSource();
public:
	OpenCLProcessor(std::string source_file);

    virtual QState mul(const QState &m1, const QState &m2);
    virtual QState tensor(const QState &m1, const QState &m2);
};
