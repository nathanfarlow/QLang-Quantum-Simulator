#include "catch.hpp"

#include "../openclprocessor.h"

TEST_CASE("Multiplication") {

	REQUIRE_NOTHROW(OpenCLProcessor("src/openclprocessor.kernel"));

	SECTION("Too small") {

	}
}

TEST_CASE("Tensor") {

}