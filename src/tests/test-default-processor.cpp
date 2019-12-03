#include <catch.hpp>

#include "../matrix.h"

TEST_CASE("Test addition") {

    Matrix<int> m1({{1, 2}, {3, 4}});

    SECTION("Constant") {

        auto m2 = m1 + 4;
        REQUIRE(m2.ToString() == "5 6\n7 8");

        m2 += 5;
        REQUIRE(m2.ToString() == "10 11\n12 13");
    }

    SECTION("Matrix") {

        Matrix<int> m2({{1, 2}, {3, 4}});
        auto m3 = m1 + m2;
        REQUIRE(m3.ToString() == "2 4\n6 8");

        m2 = Matrix<int>({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
        m2 += m2 + m2;

        REQUIRE(m2.ToString() == "3 3 3\n3 3 3\n3 3 3");

        SECTION("Dimension mismatch") {
            Matrix<int> m4({{1, 2, 4}, {3, 4, 4}});
            REQUIRE_THROWS(m1 + m4);
        }

    }

}
