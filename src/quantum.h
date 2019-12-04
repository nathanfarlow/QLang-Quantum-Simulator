#pragma once

#include <complex>

#include "matrix.h"

namespace quantum {
	//Maybe we should increase precision.
	typedef complex std::complex<float>;
	//Represents a quantum state
	typedef QState Matrix<complex>;
}
