#include <string>

#include "knight.h"

vector< vector<int> > Knight::moveOffsets = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                             {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

Knight::Knight(bool white) {
    isWhite = white;
}

string Knight::getString() {
    return "N";
}

PieceType Knight::getType() {
    return KNIGHT;
}

// vector< vector<int> > Knight::getMoves() {
//     vector< vector<int> > moves;
//     for (auto offset : Knight::moveOffsets) {
//         int newRank = rank + offset[0];
//         int newFile = file + offset[1];
//         if (newRank >= 0 && newRank < 8) {
//             if (newFile >= 0 && newFile < 8) {
//                     moves.push_back({newRank, newFile});
//             }
//         }
//     }
//     return moves;
// }