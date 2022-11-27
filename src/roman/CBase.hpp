//
// Created by nandanv on 27/11/22.
//

#ifndef NUMBER_SYSTEMS_CBASE_HPP
#define NUMBER_SYSTEMS_CBASE_HPP

#include <cstdint>
#include <string>

namespace RMN {

    class CBase {
    public:

        operator int() const{
            return m_iValue;
        }

        operator std::string() const {
            return m_sValue;
        }

        auto operator<=>(const CBase &) const = default;

    protected:
        explicit CBase(const int iValue, const std::string sValue) : m_iValue(iValue), m_sValue(sValue) {}

        int m_iValue;
        std::string m_sValue;
    };

} // RMN

#endif //NUMBER_SYSTEMS_CBASE_HPP
