#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Square;

class Bishop : public Piece {
public:
    using Piece::Piece;
    Bishop(char col, int row, char color);
    vector<Square*> getPossibleSquares() override;
private:
    void fillPossibleSquares() override;
    vector<Square*> possibleSquares;
};

#endif //BISHOP_H

