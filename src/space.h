#include "piece.h"

class Space {
    public:
        Space();
        void setPiece(Piece* p);
        Piece* getPiece();
        bool getEmpty();


    private:
        Piece* piece;
        bool isEmpty;
};