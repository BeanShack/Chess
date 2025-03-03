#ifndef BOARD_H
#define BOARD_H
#include <iostream>

#include "Square.h"
using namespace std;

class Board {
    public:
        static void setBoard();
        static Square* getSquare(char col, int row);
        static void destroy();
        static void printBoard();
    private:
        static Square* squares[8][8];

};
#endif //BOARD_H
