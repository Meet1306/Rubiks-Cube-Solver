//
// Created by Meet on 18-06-2025.
//
#include<bits/stdc++.h>
using namespace std;

#include "GenericRubiksCube.h"

class Rubiks_3D_Model : public GenericRubiksCube {
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







};
