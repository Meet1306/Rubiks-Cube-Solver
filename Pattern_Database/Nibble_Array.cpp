//
// Created by meet1 on 16-07-2025.
//

#include "Nibble_Array.h"
#include <bits/stdc++.h>
using namespace std;


//01, 23, 45 -> niddle array indexing of each 4 bit
Nibble_Array::Nibble_Array(long long n, uint8_t  val)  {
    int size =  (n+1)/2;
    v.assign(size, val);
}

int Nibble_Array::getVal(int index) {
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

