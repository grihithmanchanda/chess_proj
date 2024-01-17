#include "piece.h"

class Space {
    public:
        Space();
        void setPiece(Piece* p, int r, int f);
        Piece* getPiece();
        bool getEmpty();


    private:
        Piece* piece;
        bool isEmpty;
        int rank;
        int file;
};