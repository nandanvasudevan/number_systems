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

    std::optional<CBase> ConvertValue(const char cValue);

    static const std::set<CBase *> sNumerals{new I(), new IV(), new V(), new IX(), new X(), new XL(), new L(), new XC(),
                                             new C(),
                                             new CD(), new D(), new CM(), new M()};

    std::optional<std::string> ConvertToString(const int iValue) {
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
            uiInsertionIndex += static_cast<std::string>(optValue.value()).length();

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
                uiInsertionIndex += static_cast<std::string>(optValue.value()).length();

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

//        if (iter != sNumerals.rbegin()) {
//            const int iUpper = **std::prev(iter);
//            const int iLower = **iter;
//
//            if ((iValue - iLower) > (iUpper - iValue)) {
//                return **std::prev(iter);
//            }
//        }

        return **iter;
    }

    [[nodiscard]] std::optional<int> ConvertToNumber(const std::string_view sValue) {
        enum class EOperation {
            ADD, SUBTRACT
        };

        std::optional<CBase> optMaxRoman = std::nullopt;
        std::optional<CBase> optPrevRoman = std::nullopt;
        int iPartialSum = 0;
        int iSum = 0;
        auto eOperation = EOperation::ADD;

        for (const auto &cValue: sValue) {
            auto optRoman = ConvertValue(cValue);

            if (!optPrevRoman) {
                optPrevRoman = optRoman;
                iPartialSum = optRoman.value();
                continue;
            }

            if (!optRoman) {
                break;
            }

            if (optRoman > optPrevRoman) {
                optMaxRoman = std::nullopt;
                iSum = optRoman.value() - iPartialSum;
                /*switch (eOperation) {
                    case EOperation::ADD:
                        iSum += iPartialSum;
                        break;
                    case EOperation::SUBTRACT:
                        iSum -= iPartialSum;
                        break;
                }*/
            } else if (optRoman < optPrevRoman) {
                optMaxRoman = std::nullopt;
                iSum = optRoman.value() + iPartialSum;
            } else {
                if (!optMaxRoman.has_value() || (optMaxRoman.value() < optRoman.value())) {
                    optMaxRoman = optRoman.value();
                    iPartialSum += optRoman.value();
                } else {
                    iPartialSum += optRoman.value();
                }
            }

        }

        if (0 == iSum) {
            return std::nullopt;
        }

        return iSum;
    }

    std::optional<CBase> ConvertValue(const char cValue) {
        auto iter = std::find_if(sNumerals.rbegin(),
                                 sNumerals.rend(),
                                 [cValue](const CBase *pNumeral) {
                                     return (cValue == static_cast<std::string>(*pNumeral)[0]);
                                 });

        if (sNumerals.rend() == iter) {
            return std::nullopt;
        }

        return **iter;
    }

} // RMN