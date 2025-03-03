#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Square;

class Pawn : public Piece {
    public:
        using Piece::Piece;
        Pawn(char col, int row, char color);
        vector<Square*> getPossibleSquares() override;
    private:
        void fillPossibleSquares() override;
        vector<Square*> possibleSquares;
};

#endif //PAWN_H
