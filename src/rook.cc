#include <string>

#include "rook.h"

Rook::Rook(bool white) {
    isWhite = white;
}

string Rook::getString() {
    return "R";
}