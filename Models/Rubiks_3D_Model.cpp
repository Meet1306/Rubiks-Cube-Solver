//
// Created by Meet on 18-06-2025.
//
#include<bits/stdc++.h>
using namespace std;

#include "GenericRubiksCube.h"

class Rubiks_3D_Model : public GenericRubiksCube {
private:
    void faceRotation(int face) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= i; j++) {
                swap(rubiks_cube[face][i][j],rubiks_cube[face][j][i]);
            }
        }

        //reversing each row leading to rotation of the face
        for (int i = 0; i < 3; i++) {
            swap(rubiks_cube[face][i][0],rubiks_cube[face][i][2]);
        }

    }

    public:
    char rubiks_cube[6][3][3];  // state of the rubiks cube
    Rubiks_3D_Model() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    rubiks_cube[i][j][k] = getColorLetter(COLOR(i)); //initially solved
                }
            }
        }
    }

    COLOR getColor(FACE face, int row, int col) const override{
        int curr_color = rubiks_cube[int(face)][row][col];
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
                    if (getColor(FACE(i), j, k) != COLOR(i)) {
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
            left[i] = rubiks_cube[1][i][2];
        }

        //left from down
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[1][i][2] = rubiks_cube[5][0][i];
        }
        // down from right
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[5][0][i] = rubiks_cube[3][2-i][0];
        }
        //right from up
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[3][i][0] = rubiks_cube[0][2][i];
        }
        // up from left
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[0][2][i] = left[2-i];
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
            left[i] = rubiks_cube[1][0][i];
        }

        //left from front
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[1][0][i] = rubiks_cube[2][0][i];
        }
        // front from right
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[2][0][i] = rubiks_cube[3][0][i];
        }
        //right from back
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[3][0][i] = rubiks_cube[4][0][i];
        }
        // up from left
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[4][0][i] = left[i];
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
            top[i] = rubiks_cube[0][i][0];
        }
        //up from back
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[0][i][0] = rubiks_cube[4][2-i][2];
        }
        // back from down
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[4][i][2] = rubiks_cube[5][2-i][0];
        }
        //down from front
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[5][i][0] = rubiks_cube[2][i][0];
        }
        // front from up
        for (int i = 0; i < 3; i++)
        {
            rubiks_cube[2][i][0] = top[i];
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
            top[i] = rubiks_cube[0][i][2];
        }

        for (int i = 0; i < 3; i++)
        {
            //top from front
            rubiks_cube[0][i][2] = rubiks_cube[2][i][2];
        }

        for (int i = 0; i < 3; i++)
        {
            //front from down
            rubiks_cube[2][i][2] = rubiks_cube[5][i][2];
        }

        for (int i = 0; i < 3; i++)
        {
            //down from back
            rubiks_cube[5][i][2] = rubiks_cube[4][2-i][0];
        }

        for (int i = 0; i < 3; i++)
        {
            //back from top
            rubiks_cube[4][i][0] = top[2-i];
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
            front[i] = rubiks_cube[2][2][i];
        }

        for (int i = 0; i < 3; i++)
        {
            //front from left
            rubiks_cube[2][2][i] = rubiks_cube[1][2][i];

            //left from back
            rubiks_cube[1][2][i] = rubiks_cube[4][2][i];

            //back from right
            rubiks_cube[4][2][i] = rubiks_cube[3][2][i];

            //back from top
            rubiks_cube[3][2][i] = front[i];
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
            right[i] = rubiks_cube[3][i][2];
        }

        for (int i = 0; i < 3; i++) {
            rubiks_cube[3][i][2] = rubiks_cube[5][2][2 - i];
            rubiks_cube[5][2][2 - i] = rubiks_cube[1][2 - i][0];
            rubiks_cube[1][2 - i][0] = rubiks_cube[0][0][i];
            rubiks_cube[0][0][i] = right[i];
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

    bool operator==(const Rubiks_3D_Model& obj) const
    {
        for (int i = 0;i<6;i++)
        {
            for (int j = 0;j<3;j++)
            {
                for (int k = 0;k<3;k++)
                {
                    if (rubiks_cube[i][j][k] != obj.rubiks_cube[i][j][k]) return 0;
                }
            }
        }
        return 1;
    }

    // Rubiks_3D_Model &operator=(const Rubiks_3D_Model &obj) {
    //     for (int i = 0; i < 6; i++) {
    //         for (int j = 0; j < 3; j++) {
    //             for (int k = 0; k < 3; k++) {
    //                 rubiks_cube[i][j][k] = obj.rubiks_cube[i][j][k];
    //             }
    //         }
    //     }
    //     return *this;
    // }

};


struct Hash3d
{
    size_t operator()(const Rubiks_3D_Model& obj) const
    {
        string s;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0;j<3;j++)
            {
                for (int k = 0;k<3;k++)
                {
                    s.push_back(obj.rubiks_cube[i][j][k]);
                }
            }
        }
        return hash<string>()(s);
    }

};
