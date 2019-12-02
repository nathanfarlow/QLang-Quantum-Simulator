#include "catch.hpp"

#include "../matrix.h"

TEST_CASE("Test constructors") {
    Matrix<float> m1(2, 3);
    REQUIRE(m1.get_rows() == 2);
    REQUIRE(m1.get_cols() == 3);
}
