#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Square;

class Queen : public Piece {
public:
    using Piece::Piece;
    Queen(char col, int row, char color);
    vector<Square*> getPossibleSquares() override;
private:
    void fillPossibleSquares() override;
    vector<Square*> possibleSquares;
};

#endif //QUEEN_H

