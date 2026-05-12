#include "Engine.h"

// Конструктор: задаем стартовое состояние игры
Engine::Engine() : player1Score(0), player2Score(0) {
    // Подгружаем базу слов из файла
    dict.load("Dictionary/words.txt");

    // По правилам Балды, в центре поля должно быть стартовое слово.
    std::string startWord = "APPLE";
    for (int i = 0; i < 5; ++i) {
        board.placeLetter(i, 2, startWord[i]);
    }
    dict.addWord(startWord);
}

MoveStatus Engine::makeMove(int x, int y, char letter, const std::string& word) {
    // 1. Проверяем границы поля и свободна ли клетка
    if (x < 0 || x > 4 || y < 0 || y > 4 || board.getLetter(x, y) != ' ') {
        return MoveStatus::INVALID_PLACEMENT;
    }

    // 2. Временно ставим букву на доску
    board.placeLetter(x, y, letter);

    // 3. Проверяем наличие заявленного слова в словаре
    if (!dict.isValidWord(word)) {
        // Откатываем ход (заменяем букву обратно на пробел)
        board.placeLetter(x, y, ' ');
        return MoveStatus::NOT_IN_DICTIONARY;
    }

    // Если всё отлично, возвращаем успех.
    // Саму букву оставляем на доске.
    return MoveStatus::SUCCESS;
}

// Этот метод контроллер вызывает, когда ход успешен ИЛИ когда игроки проголосовали "За"
void Engine::approveWord(const std::string& word, int playerIndex) {
    // Если слова еще нет в словаре (house rule), добавляем его
    if (!dict.isValidWord(word)) {
        dict.addWord(word);
    }

    // Начисляем баллы (1 буква = 1 балл)
    if (playerIndex == 1) {
        player1Score += word.length();
    } else {
        player2Score += word.length();
    }
}

int Engine::getPlayer1Score() const { return player1Score; }
int Engine::getPlayer2Score() const { return player2Score; }

// Игра заканчивается, когда на поле не остается пустых клеток (' ')
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

// Метод для передачи константной доски во View для отрисовки
const Board& Engine::getBoard() const {
    return board;
}