#pragma once

#include <complex>

#include "../matrix/matrix.h"

namespace quantum {
    //Represents a quantum state's amplitude
    typedef std::complex<float> complex;
    //Represents a quantum state
    typedef Matrix<complex> QState;
}
