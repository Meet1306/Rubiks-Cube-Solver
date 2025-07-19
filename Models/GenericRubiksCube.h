//
// Created by Meet on 18-06-2025.
//
#include <bits/stdc++.h>
using namespace std;

#ifndef GENERICRUBIKSCUBE_H
#define GENERICRUBIKSCUBE_H


class GenericRubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    virtual COLOR getColor(FACE face, int row, int col) const = 0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const = 0;

    //Get Move in string
    static string getMove(MOVE ind);
    static string getInverseMove(MOVE ind);

    //Print the cube in planar format
    void print() const;

    vector<MOVE> randomShuffleCube(int times);

    void move(MOVE ind);
    void invertMove(MOVE ind);

    // void invert(MOVE ind);

    /*
     * Rotational Moves on the Rubik Cubes
     *
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */

    virtual void f() = 0;

    virtual void fPrime() = 0;

    virtual void f2() = 0;

    virtual void u() = 0;

    virtual void uPrime() = 0;

    virtual void u2() = 0;

    virtual void l() = 0;

    virtual void lPrime() = 0;

    virtual void l2() = 0;

    virtual void r() = 0;

    virtual void d() = 0;

    virtual void dPrime() = 0;

    virtual void d2() = 0;

    virtual void rPrime() = 0;

    virtual void r2() = 0;

    virtual void b() = 0;

    virtual void bPrime() = 0;

    virtual void b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};



#endif //GENERICRUBIKSCUBE_H
