#include <string>

#include "knight.h"

Knight::Knight(bool white) {
    isWhite = white;
}

string Knight::getString() {
    return "N";
}