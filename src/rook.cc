#include <string>

#include "rook.h"

Rook::Rook(bool white) {
    isWhite = white;
    hasMoved = false;
}

string Rook::getString() {
    return "R";
}

PieceType Rook::getType() {
    return ROOK;
}