#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>

#include "Square.h"
using namespace std;

class Board {
    public:
        static void setBoard();
        static Square* getSquare(char col, int row);
        static void destroy();
        static void printBoard();
        static vector<Piece*> whitePieces;
        static vector<Piece*> blackPieces;
    private:
        static Square* squares[8][8];


};
#endif //BOARD_H
