#ifndef BALDAGAME_BOARD_H
#define BALDAGAME_BOARD_H


class Board {
private:
    char grid[5][5];

public:
    Board();

    void placeLetter(int x, int y, char letter);
    char getLetter(int x, int y) const;
};


#endif