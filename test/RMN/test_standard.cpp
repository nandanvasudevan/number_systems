//
// Created by nandanv on 27/11/22.
//
#include <catch2/catch_test_macros.hpp>
#include <string>

#include "roman/standard/all.hpp"
#include "roman/Converter.hpp"

static const std::string sTag = "[roman][standard]";

namespace TEST::ROMAN {
    TEST_CASE("Defaults",
              sTag)
    {
        SECTION("I")
        {
            static constexpr int iValue = 1;
            RMN::I I;

            CHECK(I == iValue);
            CHECK("I" == std::string(I));

            CHECK("I" == RMN::CONV::ConvertToString(iValue).value());
        }

        SECTION("X")
        {
            static constexpr int iValue = 10;
            RMN::X X;

            CHECK(X == iValue);
            CHECK("X" == std::string(X));

            CHECK("X" == RMN::CONV::ConvertToString(iValue).value());
        }

        SECTION("L")
        {
            static constexpr int iValue = 50;
            RMN::L L;

            CHECK(L == iValue);
            CHECK("L" == std::string(L));

            CHECK("L" == RMN::CONV::ConvertToString(iValue).value());
        }

        SECTION("C")
        {
            static constexpr int iValue = 100;
            RMN::C C;

            CHECK(C == iValue);
            CHECK("C" == std::string(C));

            CHECK("C" == RMN::CONV::ConvertToString(iValue).value());
        }

        SECTION("D")
        {
            static constexpr int iValue = 500;
            RMN::D D;

            CHECK(D == iValue);
            CHECK("D" == std::string(D));

            CHECK("D" == RMN::CONV::ConvertToString(iValue).value());
        }

        SECTION("M")
        {
            static constexpr int iValue = 1000;
            RMN::M M;

            CHECK(M == iValue);
            CHECK("M" == std::string(M));

            CHECK("M" == RMN::CONV::ConvertToString(iValue).value());
        }
    }

    TEST_CASE("Convert to string",
              sTag)
    {
        CHECK("MMMDCCXXIV" == RMN::CONV::ConvertToString(3724).value());
        CHECK("LVI" == RMN::CONV::ConvertToString(56).value());
        CHECK("XLVIII" == RMN::CONV::ConvertToString(48).value());
        CHECK("V" == RMN::CONV::ConvertToString(5).value());
        CHECK("IV" == RMN::CONV::ConvertToString(4).value());
        CHECK("III" == RMN::CONV::ConvertToString(3).value());
    }

    TEST_CASE("Convert to number",
              sTag)
    {
        CHECK(14 == RMN::CONV::ConvertToNumber("XIV").value());
    }
} // TEST::RMN