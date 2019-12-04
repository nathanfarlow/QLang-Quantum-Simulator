#pragma once

#include <complex>

#include "matrix.h"

namespace quantum {
    //Maybe we should increase precision.
    typedef std::complex<float> complex;
    //Represents a quantum state
    typedef Matrix<complex> QState;
}
