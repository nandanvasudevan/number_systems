//
// Created by nandanv on 27/11/22.
//
#include <catch2/catch_test_macros.hpp>
#include <string>

#include "roman/standard/all.hpp"
#include "roman/Converter.hpp"

static const std::string sTag = "Roman";

namespace TEST::ROMAN {
    TEST_CASE("Defaults")

    {
        SECTION("I")
        {
            static constexpr int iValue = 1;
            RMN::I I;

            CHECK(I == iValue);
            CHECK("I" == std::string(I));

            CHECK("I" == RMN::CONV::Convert(iValue).value());
        }

        SECTION("X")
        {
            static constexpr int iValue = 10;
            RMN::X X;

            CHECK(X == iValue);
            CHECK("X" == std::string(X));

            CHECK("X" == RMN::CONV::Convert(iValue).value());
        }

        SECTION("L")
        {
            static constexpr int iValue = 50;
            RMN::L L;

            CHECK(L == iValue);
            CHECK("L" == std::string(L));

            CHECK("L" == RMN::CONV::Convert(iValue).value());
        }

        SECTION("C")
        {
            static constexpr int iValue = 100;
            RMN::C C;

            CHECK(C == iValue);
            CHECK("C" == std::string(C));

            CHECK("C" == RMN::CONV::Convert(iValue).value());
        }

        SECTION("D")
        {
            static constexpr int iValue = 500;
            RMN::D D;

            CHECK(D == iValue);
            CHECK("D" == std::string(D));

            CHECK("D" == RMN::CONV::Convert(iValue).value());
        }

        SECTION("M")
        {
            static constexpr int iValue = 1000;
            RMN::M M;

            CHECK(M == iValue);
            CHECK("M" == std::string(M));

            CHECK("M" == RMN::CONV::Convert(iValue).value());
        }
    }

    TEST_CASE("Simple conversions")
    {
        CHECK("MMMDCCXXIV" == RMN::CONV::Convert(3724).value());
    }
} // TEST::RMN