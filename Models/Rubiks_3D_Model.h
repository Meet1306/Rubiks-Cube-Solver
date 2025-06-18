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
                    rubiks_cube[i][j][k] = getColorLetter(COLOR(i)); //initially unsolved
                }
            }
        }
    }

    COLOR getColor(FACE face, int row, int col) const{
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
        for (int i = 0; i < 3; i++) {
            left[i] = rubiks_cube[1][0][i];
        }

        //for left (bottom)
        for (int i = 0; i < 3; i++) {
            rubiks_cube[1][i][2] = rubiks_cube[5][i][2];
        }

        //for bottom (right)
        for (int i = 0; i < 3; i++) {
            rubiks_cube[5][i][2] = rubiks_cube[3][2-i][0];
        }

        //for right (top)
        for (int i = 0; i < 3; i++) {
            rubiks_cube[3][i][0] = rubiks_cube[0][i][0];
        }

        //for top (left)
        for (int i = 0; i < 3; i++) {
            rubiks_cube[0][i][0] = left[2-i];
        }
    }







};
