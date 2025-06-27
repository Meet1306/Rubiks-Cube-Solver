//
// Created by Meet on 21-06-2025.
//
#include <bits/stdc++.h>
using namespace std;

#include "GenericRubiksCube.h"

class Rubiks_1D_Model : public GenericRubiksCube
{
private:
    int getIndex(int face,int row,int col) const
    {
        return face*9+row*3+col;
    }

    void faceRotation(int face) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= i; j++) {
                int index1 = face*9 + i*3 + j;
                int index2 = face*9 + j*3 + i;
                swap(rubiks_cube[index1],rubiks_cube[index2]);
            }
        }

        //reversing each row leading to rotation of the face
        for (int i = 0; i < 3; i++) {
            swap(rubiks_cube[face*9 + i*3],rubiks_cube[face*9 + i*3 + 2]);
        }

    }

    public:
    char rubiks_cube[54];  // state of the rubiks cube
    Rubiks_1D_Model() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int index = i*9 + j*3 + k;
                    rubiks_cube[index] = getColorLetter(COLOR(i)); //initially solved
                }
            }
        }
    }

    COLOR getColor(FACE face, int row, int col) const override{
        int index = getIndex(static_cast<int>(face),row,col);
        int curr_color = rubiks_cube[index];
        switch (curr_color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override{
        //the face i has the Color(i)
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (getColor(FACE(i),j,k) != COLOR(i)) {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    void f() override {
        this -> faceRotation(2);

        char left[3];
        for (int i = 0; i < 3; i++)
        {
            left[i] = rubiks_cube[getIndex(1,i,2)];
        }

        //left from down
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(1,i,2)] = rubiks_cube[getIndex(5,0,i)];
        }
        // down from right
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(5,0,i)] = rubiks_cube[getIndex(3,2-1,0)];
        }
        //right from up
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(3,i,0)] = rubiks_cube[getIndex(0,2,i)];
        }
        // up from left
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(0,2,i)] = left[2-i];
        }
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
        char left[3];
        for (int i = 0; i < 3; i++)
        {
            left[i] = rubiks_cube[getIndex(1,0,i)];
        }

        //left from front
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(1,0,i)] = rubiks_cube[getIndex(2,0,i)];
        }
        // front from right
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(2,0,i)] = rubiks_cube[getIndex(3,0,i)];
        }
        //right from back
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(3,0,i)] = rubiks_cube[getIndex(4,0,i)];
        }
        // up from left
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(4,0,i)] = left[i];
        }

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

        char top[3];
        for (int i = 0; i < 3; i++)
        {
            top[i] = rubiks_cube[getIndex(0,i,0)];
        }
        //up from back
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(0,i,0)] = rubiks_cube[getIndex(4,2-i,2)];
        }
        // back from down
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(4,i,2)] = rubiks_cube[getIndex(5,2-i,0)];
        }
        //down from front
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(5,i,0)] = rubiks_cube[getIndex(2,i,0)];
        }
        // front from up
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(2,i,0)] = top[i];
        }
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

        char top[3];
        for (int i = 0; i < 3; i++)
        {
            top[i] =rubiks_cube[getIndex(0,i,2)];
        }

        for (int i = 0; i < 3; i++)
        {
            //top from front
            rubiks_cube[getIndex(0,i,2)] = rubiks_cube[getIndex(2,i,2)];
        }

        for (int i = 0; i < 3; i++)
        {
            //front from down
            rubiks_cube[getIndex(2,i,2)] = rubiks_cube[getIndex(5,i,2)];
        }

        for (int i = 0; i < 3; i++)
        {
            //down from back
            rubiks_cube[getIndex(5,i,2)] = rubiks_cube[getIndex(4,2-i,0)];
        }

        for (int i = 0; i < 3; i++)
        {
            //back from top
           rubiks_cube[getIndex(4,i,0)] = top[2-i];
        }

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

        char front[3];
        for (int i = 0; i < 3; i++)
        {
            front[i] =  rubiks_cube[getIndex(2,2,i)];
        }

        for (int i = 0; i < 3; i++)
        {
            //front from left
            rubiks_cube[getIndex(2,2,i)] = rubiks_cube[getIndex(1,2,i)];
        }
        for (int i = 0; i < 3; i++)
        {
            //left from back
            rubiks_cube[getIndex(1,2,i)] = rubiks_cube[getIndex(4,2,i)];
        }
        for (int i = 0; i < 3; i++)
        {
            //back from right
            rubiks_cube[getIndex(4,2,i)] = rubiks_cube[getIndex(3,2,i)];
        }
        for (int i = 0; i < 3; i++)
        {
            //back from top
            rubiks_cube[getIndex(3,2,i)] = front[i];
        }
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

        char right[3];
        for (int i = 0; i < 3; i++) {
            right[i] = rubiks_cube[getIndex(3,i,2)];
        }

        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(3,i,2)] = rubiks_cube[getIndex(5,2,2-i)];
        }
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(5,2,i)] = rubiks_cube[getIndex(1,i,0)];
        }
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(1,2-i,0)] = rubiks_cube[getIndex(0,0,i)];
        }
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[getIndex(0,0,i)] = right[i];
        }
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

    bool operator==(const Rubiks_1D_Model& obj) const
    {
        for (int i = 0; i < 54; i++)
        {
            if (rubiks_cube[i] != obj.rubiks_cube[i]) return 0;
        }
        return 1;
    }

    // Rubiks_1D_Model &operator=(const Rubiks_1D_Model &obj)
    // {
    //     for (int i = 0; i < 54; i++)
    //     {
    //         rubiks_cube[i] = obj.rubiks_cube[i];
    //     }
    //     return *this;
    // }
};

struct Hash1d
{

    size_t operator()(const Rubiks_1D_Model& obj) const
    {
        string s;
        for (auto i : obj.rubiks_cube) s.push_back(i);
        return hash<string>()(s);
    }
};