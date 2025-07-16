//
// Created by meet1 on 16-07-2025.
//

#ifndef NIBBLE_ARRAY_H
#define NIBBLE_ARRAY_H

#include <bits/stdc++.h>
using namespace std;

class Nibble_Array {
private:
    vector<uint8_t > v;
public:
    Nibble_Array(long long n, uint8_t  val = 0);

    int getVal(int index);

    void setVal(int index, int val);

};



#endif //NIBBLE_ARRAY_H
