#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>

class Square;

using namespace std;

class Piece{
    public:
        Piece(char col, int row, char color);
        ~Piece();
        void move(char col, int row);
        void print() const;
        virtual vector<Square*> getPossibleSquares();
        char getColor() const;
        string getName() const;
    protected:
        virtual void fillPossibleSquares();

        vector<Square*> possibleSquares;
        char color = 'w';
        int row = 1;
        char col = 'a';
        bool pinned = false;
        string name;
};

#endif //PIECE_H
