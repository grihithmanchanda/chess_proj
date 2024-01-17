#include "space.h"

Space::Space() {
    isEmpty = true;
}

void Space::setPiece(Piece* p) {
    isEmpty = false;
    piece = p;
}

Piece* Space::getPiece() {
    return piece;
}

bool Space::getEmpty() {
    return isEmpty;
}