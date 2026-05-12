#include "Engine.h"

Engine::Engine() : player1Score(0), player2Score(0) {
    dict.load("Dictionary/words.txt");

    std::string startWord = "APPLE";
    for (int i = 0; i < 5; ++i) {
        board.placeLetter(i, 2, startWord[i]);
    }
    dict.addWord(startWord);
}

MoveStatus Engine::makeMove(int x, int y, char letter, const std::string& word) {
    if (x < 0 || x > 4 || y < 0 || y > 4 || board.getLetter(x, y) != ' ') {
        return MoveStatus::INVALID_PLACEMENT;
    }

    board.placeLetter(x, y, letter);

    if (!dict.isValidWord(word)) {
        board.placeLetter(x, y, ' ');
        return MoveStatus::NOT_IN_DICTIONARY;
    }

    return MoveStatus::SUCCESS;
}

void Engine::approveWord(const std::string& word, int playerIndex) {
    if (!dict.isValidWord(word)) {
        dict.addWord(word);
    }

    if (playerIndex == 1) {
        player1Score += word.length();
    } else {
        player2Score += word.length();
    }
}

int Engine::getPlayer1Score() const { return player1Score; }
int Engine::getPlayer2Score() const { return player2Score; }

bool Engine::isGameOver() const {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board.getLetter(j, i) == ' ') {
                return false;
            }
        }
    }
    return true;
}

const Board& Engine::getBoard() const {
    return board;
}