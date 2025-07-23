//
// Created by meet1 on 19-07-2025.
//

#ifndef CORNER_DB_MAKER_H
#define CORNER_DB_MAKER_H

#include <bits/stdc++.h>
using namespace std;

#include "Corner_Pattern_Database.h"
#include "../Models/Rubiks_BitBoard_Model.cpp"

class Corner_DB_Maker {
private:
    string fileName;
    Corner_Pattern_Database cornerDB;

public:
    Corner_DB_Maker(string _fileName);
    Corner_DB_Maker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};



#endif //CORNER_DB_MAKER_H
