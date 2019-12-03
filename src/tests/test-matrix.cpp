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

     Matrix<int> m1({{1, 2, 3},
                     {4, 5, 6}});

    SECTION("Matrix copy") {
        Matrix<int> m2(m1);
        REQUIRE(m2.ToString() == "1 2 3\n4 5 6");

        Matrix<int> m3({{1, 2},
                        {3, 4}});
        m3 = m1;
        REQUIRE(m3.ToString() == "1 2 3\n4 5 6");
    }

    SECTION("Matrix move") {
        Matrix<int> m2(std::move(m1));
        REQUIRE(m2.ToString() == "1 2 3\n4 5 6");

        Matrix<int> m3({{1, 2},
                        {3, 4}});
        m3 = std::move(m2);
        REQUIRE(m3.ToString() == "1 2 3\n4 5 6");
    }
}

TEST_CASE("Test ToString") {
    Matrix<int> m1({{1, 2},
                    {3, 4}});

    REQUIRE(m1.ToString() == "1 2\n3 4");
}