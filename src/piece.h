#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;

class Piece {
    public:
        virtual string getString() = 0;
        //virtual vector< vector<int> > getMoves(Board board) = 0;

    protected:
        bool isWhite;
};

#endif