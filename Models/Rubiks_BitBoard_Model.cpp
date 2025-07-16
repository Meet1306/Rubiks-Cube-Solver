//
// Created by Meet on 21-06-2025.
//
#include<bits/stdc++.h>
using namespace std;

#include "GenericRubiksCube.h"

class Rubiks_BitBoard_Model : public GenericRubiksCube {
private:
    long long solved_side_config[6]{};

    int getCubieColor(int face,int num)
    {
        long long faceState = rubiks_cube[face];
        long long color = (faceState>>(8ll*num) & 0xFF);
        // cout<<color<<endl;
        return color;
    }
    void setCubieColor(int face,int num, int color)
    {
        long long mask = ~(0xFFLL << (8 * num));
        rubiks_cube[face] &= mask;
        rubiks_cube[face] |= ((1LL * color)<<(8ll * num));
        // cout<<color<<endl;
        // cout<<((1LL * color)<<(8ll * num))<<endl;
        // long long cl = ((1LL * color)<<(8ll * num));
        // cout<<__builtin_ctzll(cl)<<endl;
    }


    void faceRotation(int face) {
        //W G R B O Y W G
        //0 1 2 3 4 5 6 7

        //W G W G R B O Y
        //6 7 0 1 2 3 4 5

        long long currState = rubiks_cube[face];
        long long msb_16 = currState>>(6*8);
        long long rotatedState =  currState<<(2*8);
        rotatedState |= msb_16;

        rubiks_cube[face] = rotatedState;
    }

    public:
    int arr[3][3] = {{0, 1, 2},
                     {7, 8, 3},
                     {6, 5, 4}};

    long long rubiks_cube[6];  // state of the rubiks cube
    Rubiks_BitBoard_Model() {
        for (int i = 0; i < 6; i++) { //color of the face
            long long bitColor = (1ll<<i);
            long long faceState = 0;

            for (int j = 0; j < 8; j++) //traversing in the face
            {
                long long shift = 8*j;
                long long currentCubie = (bitColor<<shift);

                faceState|=currentCubie;
            }
            solved_side_config[i] = faceState;
            rubiks_cube[i] = faceState;
        }
    }

    COLOR getColor(FACE face, int row, int col) const override{
        if (row==1 && col==1) return COLOR(int(face));

        long long num = arr[row][col];
        long long faceState = rubiks_cube[int(face)];
        long long cubie = ((faceState>>(8ll*num))&(0xFF));

        int cl = __builtin_ctzll(cubie); // count trailing zeros → gives color
        return COLOR(cl);
    }

    bool isSolved() const override{
        for (int i = 0; i < 6; i++) {
            if (solved_side_config[i] != rubiks_cube[i]) return 0;
        }
        return 1;
    }

    void f() override {
        this -> faceRotation(2);

        int top[3];
        for (int i = 0; i < 3; i++)
            top[i] = getCubieColor(0, 4 + i);  // 4  5  6

        // LEFT → UP
        for (int i = 0; i < 3; i++)
            setCubieColor(0, 4+i, getCubieColor(1, 2+i));

        // DOWN → LEFT
        for (int i = 0; i < 3; i++)
            setCubieColor(1, 2 + i, getCubieColor(5, i));

        // Right -> DOWN
        setCubieColor(5, 0, getCubieColor(3, 6));
        setCubieColor(5, 1, getCubieColor(3, 7));
        setCubieColor(5, 2, getCubieColor(3, 0));

        // TOP → RIGHT
        setCubieColor(3, 6, top[0]);
        setCubieColor(3, 7, top[1]);
        setCubieColor(3, 0, top[2]);

    }

    void fPrime() override
    {
        this->f();
        this->f();
        this->f();
    }
    void f2() override
    {
        this->f();
        this->f();
    }
    void u() override
    {
        this->faceRotation(0);
        int left[3];
        left[0] = getCubieColor(1, 0);
        left[1] = getCubieColor(1, 1);
        left[2] = getCubieColor(1, 2);

        setCubieColor(1, 0, getCubieColor(2, 0));
        setCubieColor(1, 1, getCubieColor(2, 1));
        setCubieColor(1, 2, getCubieColor(2, 2));

        setCubieColor(2, 0, getCubieColor(3, 0));
        setCubieColor(2, 1, getCubieColor(3, 1));
        setCubieColor(2, 2, getCubieColor(3, 2));

        setCubieColor(3, 0, getCubieColor(4, 0));
        setCubieColor(3, 1, getCubieColor(4, 1));
        setCubieColor(3, 2, getCubieColor(4, 2));

        setCubieColor(4, 0, left[0]);
        setCubieColor(4, 1, left[1]);
        setCubieColor(4, 2, left[2]);

    }

    void uPrime() override
    {
        this->u();
        this->u();
        this->u();

    }

    void u2() override
    {
        this->u();
        this->u();
    }

    void l() override
    {
        this -> faceRotation(1);

        int top[3];
        top[0] = getCubieColor(0, 0);
        top[1] = getCubieColor(0, 7);
        top[2] = getCubieColor(0, 6);

        setCubieColor(0, 0, getCubieColor(4, 4));
        setCubieColor(0, 7, getCubieColor(4, 3));
        setCubieColor(0, 6, getCubieColor(4, 2));

        setCubieColor(4, 2, getCubieColor(5, 6));
        setCubieColor(4, 3, getCubieColor(5, 7));
        setCubieColor(4, 4, getCubieColor(5, 0));

        setCubieColor(5, 0, getCubieColor(2, 0));
        setCubieColor(5, 7, getCubieColor(2, 7));
        setCubieColor(5, 6, getCubieColor(2, 6));

        setCubieColor(2, 0, top[0]);
        setCubieColor(2, 7, top[1]);
        setCubieColor(2, 6, top[2]);
    }

    void lPrime() override
    {
        this->l();
        this->l();
        this->l();
    }
    void l2() override
    {
        this->l();
        this->l();
    }
    void r() override
    {
        this->faceRotation(3);

        int top[3];
        top[0] = getCubieColor(0, 2);
        top[1] = getCubieColor(0, 3);
        top[2] = getCubieColor(0, 4);

        setCubieColor(0, 2, getCubieColor(2, 2));
        setCubieColor(0, 3, getCubieColor(2, 3));
        setCubieColor(0, 4, getCubieColor(2, 4));

        setCubieColor(2, 2, getCubieColor(5, 2));
        setCubieColor(2, 3, getCubieColor(5, 3));
        setCubieColor(2, 4, getCubieColor(5, 4));

        setCubieColor(5, 2, getCubieColor(4, 6));
        setCubieColor(5, 3, getCubieColor(4, 7));
        setCubieColor(5, 4, getCubieColor(4, 0));

        setCubieColor(4, 6, top[0]);
        setCubieColor(4, 7, top[1]);
        setCubieColor(4, 0, top[2]);

    }

    void rPrime() override
    {
        this->r();
        this->r();
        this->r();
    }

    void r2() override
    {
        this->r();
        this->r();
    }

    void d() override
    {
        this -> faceRotation(5);

        int left[3];
        left[0] = getCubieColor(1, 4);
        left[1] = getCubieColor(1, 5);
        left[2] = getCubieColor(1, 6);

        setCubieColor(1, 4, getCubieColor(4, 4));
        setCubieColor(1, 5, getCubieColor(4, 5));
        setCubieColor(1, 6, getCubieColor(4, 6));

        setCubieColor(4, 4, getCubieColor(3, 4));
        setCubieColor(4, 5, getCubieColor(3, 5));
        setCubieColor(4, 6, getCubieColor(3, 6));

        setCubieColor(3, 4, getCubieColor(2, 4));
        setCubieColor(3, 5, getCubieColor(2, 5));
        setCubieColor(3, 6, getCubieColor(2, 6));

        setCubieColor(2, 4, left[0]);
        setCubieColor(2, 5, left[1]);
        setCubieColor(2, 6, left[2]);
    }

    void dPrime() override
    {
        this->d();
        this->d();
        this->d();

    }

    void d2() override
    {
        this->d();
        this->d();
    }

    void b() override {
        this->faceRotation(4);

        int top[3];
        top[0] = getCubieColor(0, 0);
        top[1] = getCubieColor(0, 1);
        top[2] = getCubieColor(0, 2);

        setCubieColor(0, 0, getCubieColor(3, 2));
        setCubieColor(0, 1, getCubieColor(3, 3));
        setCubieColor(0, 2, getCubieColor(3, 4));

        setCubieColor(3, 2, getCubieColor(5, 4));
        setCubieColor(3, 3, getCubieColor(5, 5));
        setCubieColor(3, 4, getCubieColor(5, 6));

        setCubieColor(5, 4, getCubieColor(1, 6));
        setCubieColor(5, 5, getCubieColor(1, 7));
        setCubieColor(5, 6, getCubieColor(1, 0));

        setCubieColor(1, 6, top[0]);
        setCubieColor(1, 7, top[1]);
        setCubieColor(1, 0, top[2]);
    }

    void bPrime() override
    {
        this->b();
        this->b();
        this->b();
    }

    void b2() override
    {
        this->b();
        this->b();
    }

    bool operator==(const Rubiks_BitBoard_Model& obj) const
    {
        for (int i = 0; i < 6; i++)
        {
            if (rubiks_cube[i]!=obj.rubiks_cube[i]) return 0;
        }
        return 1;
    }

};

struct HashBitBoard
{
    size_t operator()(const Rubiks_BitBoard_Model& obj) const
    {
        string s;
        for (int i = 0;i<6;i++)
        {
            long long num = obj.rubiks_cube[i];
            for (int j = 0;j<3;j++)
            {
                for (int k = 0;k<3;k++)
                {
                    if (j==1 && k==1)
                    {
                        char ch = obj.getColorLetter(GenericRubiksCube::COLOR(i));
                        s.push_back(ch);
                        continue;
                    }
                    long long idx_8 = obj.arr[j][k];
                    long long one_8 = 0xFF;

                    int cl = (num>>(idx_8*8))&one_8;

                    int indx = __builtin_ctz(cl);
                    char ch = obj.getColorLetter(GenericRubiksCube::COLOR(indx));
                    s.push_back(ch);

                }
            }
        }
        return hash<string>()(s);

    }
};

