//
// Created by meet1 on 16-07-2025.
//

#include "Nibble_Array.h"
#include <bits/stdc++.h>
using namespace std;


//01, 23, 45 -> nibble array indexing of each 4 bit
Nibble_Array::Nibble_Array(long long n, uint8_t val)  {
    size =  (n+1)/2;
    v.assign(size, val);
}

int Nibble_Array::getVal(int index) const {
    int nib_idx = index/2;
    if (index&1) {
        return v[nib_idx]&0x0F;
    }
    else {
        return v[nib_idx]>>4;
    }

}

void Nibble_Array::setVal(int index, int val) {
    int nib_idx = index/2;
    if (index&1) {
        v[nib_idx] &= 0xF0;
        v[nib_idx] |= val;
    }
    else {
        v[nib_idx] &= 0x0F;
        v[nib_idx] |= (val<<4);
    }
}

const uint8_t *Nibble_Array::data() const {
    return this->v.data();
}

size_t Nibble_Array::storageSize() const {
    return this->v.size();
}

// Move all the moves to a vector. This doubles the size, but is faster to access,
// since there is no bitwise operation needed.
void Nibble_Array::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);

    for (unsigned i = 0; i < this->size; ++i)
        dest.push_back(this->getVal(i));
}

// Reset the array
void Nibble_Array::reset(const uint8_t val) {
    fill(this->v.begin(), this->v.end(), val);
}

