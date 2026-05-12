#include "Board.h"

Board::Board() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = ' ';
        }
    }
}

void Board::placeLetter(int x, int y, char letter) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        grid[y][x] = letter;
    }
}

char Board::getLetter(int x, int y) const {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        return grid[y][x];
    }
    return ' ';
}