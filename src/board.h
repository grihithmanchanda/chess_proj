#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
#include "space.h"
#include "queen.h"

using namespace std;

class Board {
    public:
        Board();
        vector< vector<Space> > board;
        Piece* getPiece(int rank, int file);
        void setPiece(Piece* piece, int rank, int file);
};

int main();

#endif