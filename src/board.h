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

typedef set< vector<int> > move_list;

class Board {
    public:
        Board();
        vector< vector<Space> > board;
        Piece* getPiece(int rank, int file);
        void setPiece(Piece* piece, int rank, int file);
        void getMoves(Piece* piece, move_list* moves, bool forChecks);

    private:
        void knightMoves(Piece* piece, move_list* moves, bool forChecks);
        static vector< vector<int> > knightMoveOffsets;

        void bishopMoves(Piece* piece, move_list* moves, bool forChecks);

        void rookMoves(Piece* piece, move_list* moves, bool forChecks);

        void pawnMoves(Pawn* pawn, move_list* moves, bool forChecks);

        void kingMoves(King* king, move_list* moves, bool forChecks);

        bool underAttack(int rank, int file, bool isKingWhite);

        void addCastles(King* king, move_list* moves);
};

int main();

#endif