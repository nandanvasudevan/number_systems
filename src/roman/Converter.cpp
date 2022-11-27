//
// Created by nandanv on 27/11/22.
//

#include <algorithm>
#include <set>
#include <optional>
#include "Converter.hpp"

#include "standard/all.hpp"

namespace RMN::CONV {
    std::optional<CBase> ConvertValue(const int iValue);

    static const std::set<CBase *> sNumerals{new I(), new V(), new X(), new L(), new C(), new D(), new M()};

    std::optional<std::string> Convert(const int iValue) {
        std::string sValue{};

        auto optValue = ConvertValue(iValue);

        if (!optValue) {
            return std::nullopt;
        }

        {
            size_t uiInsertionIndex = 0;
            int iLastValue = iValue;
            bool bPrefix = false;

            sValue += std::string(optValue.value());
            uiInsertionIndex++;

            if (iLastValue < optValue.value()) {
                optValue = ConvertValue(optValue.value() - iLastValue);
                bPrefix = true;
            } else {
                bPrefix = false;
            }

            while (0 != optValue.value()) {
                auto iDifference = iLastValue - optValue.value();

                if (bPrefix) {
                    iDifference = optValue.value();
                }

                iLastValue = iDifference;

                optValue = ConvertValue(iDifference);

                if (!optValue) {
                    break;
                }

                if (bPrefix) {
                    sValue.insert(uiInsertionIndex - 1,
                                  optValue.value());
                } else {
                    sValue.insert(uiInsertionIndex,
                                  optValue.value());
                }
                uiInsertionIndex++;

                if (iDifference < optValue.value()) {
                    optValue = ConvertValue(optValue.value() - iDifference);
                    bPrefix = true;
                } else {
                    bPrefix = false;
                }
            }
        }

        return sValue;
    }

    std::optional<CBase> ConvertValue(const int iValue) {
        if (iValue <= 0) {
            return std::nullopt;
        }

        auto iter = std::find_if(sNumerals.rbegin(),
                                 sNumerals.rend(),
                                 [iValue](const CBase *pNumeral) {
                                     return (iValue >= *pNumeral);
                                 });

        if (sNumerals.rend() == iter) {
            return std::nullopt;
        }

        if (iter != sNumerals.rbegin()) {
            const int iUpper = **std::prev(iter);
            const int iLower = **iter;

            if ((iValue - iLower) > (iUpper - iValue)) {
                return **std::prev(iter);
            }
        }

        return **iter;
    }
} // RMN