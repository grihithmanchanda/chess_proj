#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
    public:
        Bishop(bool white);
        string getString();
        vector< vector<int> > getMoves();
};

#endif