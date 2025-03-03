#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Square;

class Rook : public Piece {
public:
    using Piece::Piece;
    Rook(char col, int row, char color);
    vector<Square*> getPossibleSquares() override;
private:
    void fillPossibleSquares() override;
    vector<Square*> possibleSquares;
};

#endif //ROOK_H

