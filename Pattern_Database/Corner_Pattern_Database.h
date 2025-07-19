//
// Created by meet1 on 19-07-2025.
//

#ifndef CORNER_PATTERN_DATABASE_H
#define CORNER_PATTERN_DATABASE_H

#include "../Models/GenericRubiksCube.h"
#include "Pattern_Database.h"
#include "PermutationIndexer.h"

#include <bits/stdc++.h>
using namespace std;

class Corner_Pattern_Database : public Pattern_Database {
    typedef GenericRubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    Corner_Pattern_Database();
    Corner_Pattern_Database(uint8_t init_val);
    uint32_t getDatabaseIndex(const GenericRubiksCube& cube) const;
};



#endif //CORNER_PATTERN_DATABASE_H
