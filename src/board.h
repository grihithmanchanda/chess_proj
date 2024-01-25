#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <set>
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
        void getMoves(Piece* piece, set< vector<int> >* moves);

    private:
        void knightMoves(Piece* piece, set< vector<int> >* moves);
        static vector< vector<int> > knightMoveOffsets;

        void bishopMoves(Piece* piece, set< vector<int> >* moves);

        void rookMoves(Piece* piece, set< vector<int> >* moves);
};

int main();

#endif