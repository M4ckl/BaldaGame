#ifndef BALDAGAME_ENGINE_H
#define BALDAGAME_ENGINE_H

#include <string>
#include "Board.h"
#include "Dictionary.h"
#include "MoveStatus.h"

class Engine {
private:
    Board board;
    Dictionary dict;
    int player1Score;
    int player2Score;

public:
    Engine();

    MoveStatus makeMove(int x, int y, char letter, const std::string& word);
    void approveWord(const std::string& word, int playerIndex);

    int getPlayer1Score() const;
    int getPlayer2Score() const;
    bool isGameOver() const;

    const Board& getBoard() const;
};


#endif