//
// Created by meet1 on 16-07-2025.
//

#ifndef PATTERN_DATABASE_H
#define PATTERN_DATABASE_H

#include "../Models/GenericRubiksCube.h"
#include "Nibble_Array.h"
#include <bits/stdc++.h>
using namespace std;

class Pattern_Database {
public:
    Nibble_Array database;
    long long size;
    long long numItems;

    Pattern_Database(const size_t size);

    Pattern_Database(const long long size, uint8_t init_val);

    void toFile(const string &filePath) const;

    bool fromFile(const string &filePath);

    virtual uint32_t getDatabaseIndex(const GenericRubiksCube &cube) const = 0;  //pure virtual

    bool setNumMoves(const GenericRubiksCube &cube, const uint8_t numMoves);

    bool setNumMoves(const long long ind, const uint8_t numMoves);

    uint8_t getNumMoves(const GenericRubiksCube &cube) const;

    uint8_t getNumMoves(const long long ind) const;

    size_t getSize() const;

    size_t getNumItems() const;

    bool isFull() const;

    vector<uint8_t> inflate() const;

    void reset();

};



#endif //PATTERN_DATABASE_H
