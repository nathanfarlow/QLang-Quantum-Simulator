#include "catch.hpp"

#include "../matrix.h"

TEST_CASE("Test constructors") {

    SECTION("Dimensions") {
        Matrix<float> m1(2, 3);
        REQUIRE(m1.get_rows() == 2);
        REQUIRE(m1.get_cols() == 3);
    }

    SECTION("Preinitialization") {
        Matrix<int> m1({{1, 2},
                        {3, 4}});
        REQUIRE(m1.get_rows() == 2);
        REQUIRE(m1.get_cols() == 2);

        REQUIRE((m1[0][0] == 1
            &&  m1[0][1] == 2
            &&  m1[1][0] == 3
            &&  m1[1][1] == 4));
    }
}
