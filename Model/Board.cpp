#include "Board.h"

// Конструктор: заполняем сетку 5x5 символами пробела (пустыми клетками)
Board::Board() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = ' ';
        }
    }
}

// Метод для размещения буквы на доске.
// Мы не делаем здесь сложных проверок (это работа Engine), просто ставим букву.
void Board::placeLetter(int x, int y, char letter) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        grid[y][x] = letter; // Обрати внимание: y - это строка (wiersz), x - колонка (kolumna)
    }
}

// Метод для получения буквы с доски.
char Board::getLetter(int x, int y) const {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) {
        return grid[y][x];
    }
    return ' '; // Возвращаем пробел, если координаты выходят за пределы поля
}