//
// Created by meet1 on 16-07-2025.
//

#ifndef NIBBLE_ARRAY_H
#define NIBBLE_ARRAY_H

#include <bits/stdc++.h>

using namespace std;

class Nibble_Array {
private:
    vector<uint8_t> v;
    int size;
public:
    Nibble_Array(long long n, uint8_t val = 0xFF);  //0xFF for only if newSetValue is <oldSet than only set

    int getVal(int index) const;

    void setVal(int index, int val);

    uint8_t *data();

    const uint8_t *data() const;

    size_t storageSize() const;

    void inflate(vector<uint8_t> &dest) const;

    void reset(const uint8_t val = 0xFF);


};



#endif //NIBBLE_ARRAY_H
