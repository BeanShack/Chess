#ifndef KING_H
#define KING_H
#include "Piece.h"

class Square;

class King : public Piece {
public:
    using Piece::Piece;
    King(char col, int row, char color);
    vector<Square*> getPossibleSquares() override;
    bool isCheckmated();
private:
    void fillPossibleSquares() override;
    vector<Square*> possibleSquares;
};

#endif //KING_H
