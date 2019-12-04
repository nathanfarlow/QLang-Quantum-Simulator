#include "catch.hpp"

#include "../openclprocessor.h"

using namespace quantum;

TEST_CASE("Multiplication") {

	auto opencl_processor = std::make_shared<OpenCLProcessor>("src/openclprocessor.kernel");

	QState s1({{complex(1, 3), complex(2, 2)}, {complex(3), complex(4, 1)}});
	QState s2(s1);

	QState expected = s1 * s2;

	s1.set_processor(opencl_processor);
	QState received = s1 * s2;

	REQUIRE(expected.ToString() == received.ToString());

	SECTION("Too small") {

	}
}

TEST_CASE("Tensor") {

}