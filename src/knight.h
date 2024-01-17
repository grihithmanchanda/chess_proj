#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>

#include "piece.h"

class Knight : public Piece {
    public:
        Knight(bool white);
        string getString();
        vector< vector<int> > getMoves();

    private:
        static vector< vector<int> > moveOffsets;
};

#endif