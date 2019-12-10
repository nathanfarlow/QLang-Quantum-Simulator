#include "catch.hpp"

#include "qcircuit.h"

using namespace quantum;

TEST_CASE("Quantum circuit is initialized") {
    QCircuit c(2);

    c.InitZero();

    REQUIRE(c.state_.ToString() == "(1,0)\n(0,0)\n(0,0)\n(0,0)");

    c.Init("10");

    REQUIRE(c.state_.ToString() == "(0,0)\n(0,0)\n(1,0)\n(0,0)");
}

TEST_CASE("Compute unary") {
    QCircuit c(2);
    c.Init("01");

    c.AddOperation(QOperation(definitions["X"], 1, 0));
    c.AddOperation(QOperation(definitions["X"], 1, 0));
    c.AddOperation(QOperation(definitions["ID"], 1, 0));

    REQUIRE(c.Compute().ToString() == "(0,0)\n(1,0)\n(0,0)\n(0,0)");
}

TEST_CASE("Test swap") {
    QCircuit c(2);
    c.Init("10");

    c.Swap(c.state_, 1, 0);

    REQUIRE(c.state_.ToString() == "(0,0)\n(1,0)\n(0,0)\n(0,0)");

    QCircuit c1(3);
    c1.Init("100");
    c1.Swap(c1.state_, 0, 2);

    REQUIRE(c1.state_.ToString() == "(0,0)\n(1,0)\n(0,0)\n(0,0)\n(0,0)\n(0,0)\n(0,0)\n(0,0)");
}

TEST_CASE("Compute binary") {
    QCircuit c(3);
    c.Init("010");

    c.AddOperation(QOperation(definitions["CNOT"], 2, 1));

    REQUIRE(c.Compute().ToString() == "(0,0)\n(0,0)\n(1,0)\n(0,0)\n(0,0)\n(0,0)\n(0,0)\n(0,0)");

    QCircuit c1(2);
    c1.Init("01");
    c1.AddOperation(QOperation(definitions["CNOT"], 1, 0));
    REQUIRE(c1.Compute().ToString() == "(0,0)\n(0,0)\n(0,0)\n(1,0)");
}