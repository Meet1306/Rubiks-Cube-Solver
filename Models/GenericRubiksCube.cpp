//
// Created by Meet on 18-06-2025.
//
#include <bits/stdc++.h>
using namespace std;
#include "GenericRubiksCube.h"


char GenericRubiksCube::getColorLetter(COLOR color)
{
    /*
    * enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
     */
    if (color == GenericRubiksCube::COLOR::WHITE)
    {
        return 'W';
    }
    else if (color == GenericRubiksCube::COLOR::GREEN)
    {
        return 'G';
    }
    else if (color == GenericRubiksCube::COLOR::BLUE)
    {
        return 'B';
    }
    else if (color == GenericRubiksCube::COLOR::RED)
    {
        return 'R';
    }
    else if (color == GenericRubiksCube::COLOR::ORANGE)
    {
        return 'O';
    }
    else if (color == GenericRubiksCube::COLOR::YELLOW)
    {
        return 'Y';
    }
}

//static string getMove(MOVE ind);

string GenericRubiksCube::getMove(MOVE ind) {
    switch (ind) {
    case MOVE::L:
        return "L";
    case MOVE::LPRIME:
        return "L'";
    case MOVE::L2:
        return "L2";
    case MOVE::R:
        return "R";
    case MOVE::RPRIME:
        return "R'";
    case MOVE::R2:
        return "R2";
    case MOVE::U:
        return "U";
    case MOVE::UPRIME:
        return "U'";
    case MOVE::U2:
        return "U2";
    case MOVE::D:
        return "D";
    case MOVE::DPRIME:
        return "D'";
    case MOVE::D2:
        return "D2";
    case MOVE::F:
        return "F";
    case MOVE::FPRIME:
        return "F'";
    case MOVE::F2:
        return "F2";
    case MOVE::B:
        return "B";
    case MOVE::BPRIME:
        return "B'";
    case MOVE::B2:
        return "B2";
    }
}

void GenericRubiksCube::move(MOVE ind) {
    switch (ind) {
    case MOVE::L:
        return this->l();
    case MOVE::LPRIME:
        return this->lPrime();
    case MOVE::L2:
        return this->l2();
    case MOVE::R:
        return this->r();
    case MOVE::RPRIME:
        return this->rPrime();
    case MOVE::R2:
        return this->r2();
    case MOVE::U:
        return this->u();
    case MOVE::UPRIME:
        return this->uPrime();
    case MOVE::U2:
        return this->u2();
    case MOVE::D:
        return this->d();
    case MOVE::DPRIME:
        return this->dPrime();
    case MOVE::D2:
        return this->d2();
    case MOVE::F:
        return this->f();
    case MOVE::FPRIME:
        return this->fPrime();
    case MOVE::F2:
        return this->f2();
    case MOVE::B:
        return this->b();
    case MOVE::BPRIME:
        return this->bPrime();
    case MOVE::B2:
        return this->b2();
    }
}


void GenericRubiksCube::print() const
{

    //up face
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<" ";
        }
        cout<<" ";

        for (int j = 0; j < 3; j++)
        {
            cout<<getColorLetter(getColor(FACE(0),i,j));
        }cout<<endl;
    }
    cout<<endl;


    for (int i = 0; i < 3; i++)
    {
        //left face
        for (int j = 0; j < 3; j++)
        {
            cout<<getColorLetter(getColor(FACE(1),i,j));
        }
        cout<<" ";

        //front face
        for (int j = 0; j < 3; j++)
        {
            cout<<getColorLetter(getColor(FACE(2),i,j));
        }
        cout<<" ";


        //right face
        for (int j = 0; j < 3; j++)
        {
            cout<<getColorLetter(getColor(FACE(3),i,j));
        }
        cout<<" ";

        //back face
        for (int j = 0; j < 3; j++)
        {
            cout<<getColorLetter(getColor(FACE(4),i,j));
        }
        cout<<" ";


        cout<<endl;
    }
    cout<<endl;

    //down face
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<" ";
        }
        cout<<" ";

        for (int j = 0; j < 3; j++)
        {
            cout<<getColorLetter(getColor(FACE(5),i,j));
        }cout<<endl;
    }
    cout<<endl;

}

vector<GenericRubiksCube::MOVE> GenericRubiksCube::randomShuffleCube(int times) {
    vector<MOVE> moves;
    srand(time(0));
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (rand() % 18);
        moves.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
        // cout<<getMove(static_cast<MOVE>(selectMove))<<endl;
        // this->print();
    }
    return moves;
}


