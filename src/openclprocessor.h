#pragma once

#include "defaultprocessor.h"
#include "quantum.h"

using quantum::complex;
using quantum::QState;

class OpenClProcessor : public DefaultProcessor<complex> {
public:
    QState mul(const QState &m1, const QState &m2);
    QState tensor(const QState &m1, const QState &m2);
};

#include "openclprocessor.tpp"
