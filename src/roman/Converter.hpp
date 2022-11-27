//
// Created by nandanv on 27/11/22.
//

#ifndef NUMBER_SYSTEMS_CONVERTER_HPP
#define NUMBER_SYSTEMS_CONVERTER_HPP

#include <optional>
#include <string>
#include <string_view>

namespace RMN::CONV {

    /**
     * @brief Convert a number into a roman numeral string.
     * @param iValue Value to be converted
     * @returns `std::nullopt` if conversion was not possible.
     * @returns `std::string` representation of the value.
     */
    [[nodiscard]] std::optional<std::string> ConvertToString(const int iValue);

    [[nodiscard]] std::optional<int> ConvertToNumber(const std::string_view sValue);

} // RMN

#endif //NUMBER_SYSTEMS_CONVERTER_HPP
