#ifndef SQUARE_H
#define SQUARE_H

using namespace std;
#include <iostream>
#include <vector>

class Piece;

class Square {
    public:
        Square();
        Square(int row, char col);
        ~Square();
        Piece* getPiece();
        void setPiece(Piece* piece);
        void print();
        bool checkAttacked(char color);
        void addAttacking(Piece* piece);
        void clearAttacking();

    private:
        vector<Piece*> attackingPieces;
        char col = 'a';
        int row = 0;
        Piece* piece;
};

#endif //SQUARE_H
