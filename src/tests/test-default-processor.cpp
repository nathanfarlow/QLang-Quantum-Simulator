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

TEST_CASE("Test subtraction") {
    Matrix<int> m1({{1, 2}, {3, 4}});

    SECTION("Constant") {

        auto m2 = m1 - 4;
        REQUIRE(m2.ToString() == "-3 -2\n-1 0");

        m2 -= 5;
        REQUIRE(m2.ToString() == "-8 -7\n-6 -5");
    }

    SECTION("Matrix") {

        Matrix<int> m2({{1, 2}, {3, 4}});
        auto m3 = m1 - m2;
        REQUIRE(m3.ToString() == "0 0\n0 0");

        m2 = Matrix<int>({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
        m2 -= m2 - m2;

        REQUIRE(m2.ToString() == "1 1 1\n1 1 1\n1 1 1");

        SECTION("Dimension mismatch") {
            Matrix<int> m4({{1, 2, 4}, {3, 4, 4}});
            REQUIRE_THROWS(m1 - m4);
        }

    }
}

TEST_CASE("Test multiplication") {

    SECTION("Constant") {
        Matrix<int> m1({{4, 0}, {1, -9}});
        auto m2 = m1 * 2;

        REQUIRE(m2.ToString() == "8 0\n2 -18");
    }

    SECTION("Matrix") {
        Matrix<int> m1({{3, 4, 2}});

        Matrix<int> m2({{13, 9, 7, 15},
                        {8, 7, 4, 6},
                        {6, 4, 0, 3}});

        auto m3 = m1 * m2;

        REQUIRE(m3.ToString() == "83 63 37 75");

        SECTION("Dimension mismatch") {
            Matrix<int> m4({{1, 2}});
            REQUIRE_THROWS(m1 * m4);
        }
    }
}