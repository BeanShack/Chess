#ifndef SQUARE_H
#define SQUARE_H

using namespace std;
#include <iostream>

class Piece;

class Square {
    public:
        Square();
        Square(int row, char col);
        ~Square();
        Piece* getPiece();
        void setPiece(Piece* piece);
        void print();

    private:
        char col = 'a';
        int row = 0;
        Piece* piece;
};

#endif //SQUARE_H
