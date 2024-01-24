#include <string>

#include "bishop.h"

Bishop::Bishop(bool white) {
    isWhite = white;
}

string Bishop::getString() {
    return "B";
}

PieceType Bishop::getType() {
    return BISHOP;
}