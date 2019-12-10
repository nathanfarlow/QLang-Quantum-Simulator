#include "catch.hpp"

#include "qlang.h"

using namespace quantum;

TEST_CASE("Simple script parsing") {

	QLangParser parser;

	std::string program = std::string("circuit 2 11\n")
			+ "x 0\n";

	QCircuit *c = parser.Compile(program);

	REQUIRE(c->Compute().ToString() == "asdf");

	delete c;
}