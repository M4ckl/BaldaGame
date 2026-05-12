#include "GameController.h"
#include <iostream>
#include <string>

GameController::GameController(IView* viewInterface) : view(viewInterface), currentPlayer(1) {}

void GameController::play() {
    std::string temp;

    // Главный игровой цикл: работает, пока на поле есть пустые клетки
    while (!engine.isGameOver()) {
        view->drawBoard(engine.getBoard());

        // Выводим текущий счет
        std::string scoreMsg = "Wynik - Gracz 1: " + std::to_string(engine.getPlayer1Score()) +
                               " | Gracz 2: " + std::to_string(engine.getPlayer2Score());
        view->showMessage(scoreMsg);
        view->showMessage("Tura gracza " + std::to_string(currentPlayer));

        // Переменные для получения хода от пользователя
        int x, y;
        char letter;
        std::string word;

        // Запрашиваем ввод
        view->requestMove(x, y, letter, word);

        // Передаем данные в Model
        MoveStatus status = engine.makeMove(x, y, letter, word);

        // Обрабатываем результат хода
        if (status == MoveStatus::SUCCESS) {
            engine.approveWord(word, currentPlayer); // Начисляем баллы
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Смена игрока
        }
        else if (status == MoveStatus::INVALID_PLACEMENT) {
            view->showMessage("Błąd: Nieprawidłowe ułożenie litery. Spróbuj ponownie.");
            // Игрока не меняем, он должен переходить
            std::cout << "Wpisz dowolny znak i naciśnij Enter, aby kontynuować... ";
            std::cin >> temp;
        }
        else if (status == MoveStatus::NOT_IN_DICTIONARY) {
            // House rule: голосование игроков
            bool confirmed = view->askConfirmation(word);

            if (confirmed) {
                engine.approveWord(word, currentPlayer); // Добавляем слово в словарь и даем очки
                engine.makeMove(x, y, letter, word);     // Вызываем еще раз, чтобы буква осталась на доске
                view->showMessage("Słowo dodane do słownika!");
            } else {
                view->showMessage("Słowo odrzucone. Tracisz kolejkę!");
            }

            // По правилам, после голосования ход переходит к следующему игроку в любом случае
            currentPlayer = (currentPlayer == 1) ? 2 : 1;

            std::cout << "Wpisz dowolny znak i naciśnij Enter, aby kontynuować... ";
            std::cin >> temp;
        }
    }

    // Обработка окончания игры
    view->drawBoard(engine.getBoard());
    view->showMessage("KONIEC GRY!");

    int s1 = engine.getPlayer1Score();
    int s2 = engine.getPlayer2Score();

    view->showMessage("Koncowy wynik - Gracz 1: " + std::to_string(s1) + " | Gracz 2: " + std::to_string(s2));

    if (s1 > s2) {
        view->showMessage("Wygrywa Gracz 1!");
    } else if (s2 > s1) {
        view->showMessage("Wygrywa Gracz 2!");
    } else {
        view->showMessage("Remis!");
    }
}