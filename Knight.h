#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Square;

class Knight : public Piece {
public:
    using Piece::Piece;
    Knight(char col, int row, char color);
    vector<Square*> getPossibleSquares() override;
private:
    void fillPossibleSquares() override;
    vector<Square*> possibleSquares;
};

#endif //KNIGHT_H
