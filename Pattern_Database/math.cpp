//
// Created by konar on 15-07-2025.
//

#include "math.h"

uint32_t factorial(uint32_t n)
{
    if (n==0) return 1;
    return factorial(n-1)*n;
}

//nPk: n!/(n-k)!.
uint32_t pick(uint32_t n, uint32_t k)
{
    return factorial(n) / factorial(n - k);
}

// nCk: n!/((n-k)!*k!).
uint32_t choose(uint32_t n, uint32_t k)
{
    if (n<k) return 0;
    return factorial(n) / (factorial(n - k) * factorial(k));
}