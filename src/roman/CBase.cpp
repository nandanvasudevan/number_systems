//
// Created by nandanv on 27/11/22.
//

#include "CBase.hpp"

namespace RMN {

    auto operator<=>(const CBase oBase, const int iValue)
    {
        return iValue <=> static_cast<int>(oBase);
    }

//    bool operator==(int lhs, CBase rhs) {
//        return (lhs == static_cast<int>(rhs));
//    }
//
//    bool operator==(CBase lhs, int rhs) {
//        return (static_cast<int>(lhs) == rhs);
//    }
//
//    bool operator!=(int lhs, CBase rhs) {
//        return !(lhs == static_cast<int>(rhs));
//    }
//
//    bool operator!=(CBase lhs, int rhs) {
//        return !(static_cast<int>(lhs) == rhs);
//    }
//
//    bool operator<(int lhs, CBase rhs) {
//        return (lhs < static_cast<int>(rhs));
//    }
//
//    bool operator<(CBase lhs, int rhs) {
//        return (static_cast<int>(lhs) < rhs);
//    }
//
//    bool operator<=(int lhs, CBase rhs) {
//        return ((lhs < static_cast<int>(rhs)) || (lhs == static_cast<int>(rhs)));
//    }
//
//    bool operator<=(CBase lhs, int rhs) {
//        return ((static_cast<int>(lhs) < rhs) || (static_cast<int>(lhs) == rhs));
//    }
//
//    bool operator>(int lhs, CBase rhs) {
//        return !(lhs < static_cast<int>(rhs));
//    }
//
//    bool operator>(CBase lhs, int rhs) {
//        return !(static_cast<int>(lhs) < rhs);
//    }
//
//    bool operator>=(int lhs, CBase rhs) {
//        return ((lhs > static_cast<int>(rhs)) || (lhs == static_cast<int>(rhs)));
//    }
//
//    bool operator>=(CBase lhs, int rhs) {
//        return ((static_cast<int>(lhs) > rhs) || (static_cast<int>(lhs) == rhs));
//    }
    
} // RMN