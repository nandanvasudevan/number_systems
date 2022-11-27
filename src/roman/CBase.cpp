//
// Created by nandanv on 27/11/22.
//

#include "CBase.hpp"

namespace RMN {

    auto operator<=>(const CBase oBase, const int iValue)
    {
        return iValue <=> static_cast<int>(oBase);
    }
    
} // RMN