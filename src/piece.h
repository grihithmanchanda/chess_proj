#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;

class Piece {
    public:
        virtual string getString() = 0;
        void setRank(int r);
        void setFile(int f);
        //virtual vector< vector<int> > getMoves() = 0;

    protected:
        bool isWhite;
        int rank;
        int file;
};

#endif