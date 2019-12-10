#include "catch.hpp"

#include "qcircuit.h"

using namespace quantum;

TEST_CASE("Quantum circuit is initialized") {
	QCircuit c(2);

	c.InitZero();

	REQUIRE(c.state_.ToString() == "(1,0)\n(0,0)\n(1,0)\n(0,0)");

	c.Init("10");

	REQUIRE(c.state_.ToString() == "(0,0)\n(1,0)\n(1,0)\n(0,0)");
}