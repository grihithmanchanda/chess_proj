#include "space.h"

Space::Space() {
    isEmpty = true;
}

void Space::setPiece(Piece* p, int r, int f) {
    isEmpty = false;
    piece = p;
    rank = r;
    file = f;
}

Piece* Space::getPiece() {
    return piece;
}

bool Space::getEmpty() {
    return isEmpty;
}