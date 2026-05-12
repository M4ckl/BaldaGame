#include "GameController.h"
#include <iostream>
#include <string>

GameController::GameController(IView* viewInterface) : view(viewInterface), currentPlayer(1) {}

void GameController::play() {
    std::string temp;

    while (!engine.isGameOver()) {
        view->drawBoard(engine.getBoard());

        std::string scoreMsg = "Wynik - Gracz 1: " + std::to_string(engine.getPlayer1Score()) +
                               " | Gracz 2: " + std::to_string(engine.getPlayer2Score());
        view->showMessage(scoreMsg);
        view->showMessage("Tura gracza " + std::to_string(currentPlayer));

        int x, y;
        char letter;
        std::string word;

        view->requestMove(x, y, letter, word);

        MoveStatus status = engine.makeMove(x, y, letter, word);

        if (status == MoveStatus::SUCCESS) {
            engine.approveWord(word, currentPlayer);
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
        else if (status == MoveStatus::INVALID_PLACEMENT) {
            view->showMessage("Błąd: Nieprawidłowe ułożenie litery. Spróbuj ponownie.");
            std::cout << "Wpisz dowolny znak i naciśnij Enter, aby kontynuować... ";
            std::cin >> temp;
        }
        else if (status == MoveStatus::NOT_IN_DICTIONARY) {
            bool confirmed = view->askConfirmation(word);

            if (confirmed) {
                engine.approveWord(word, currentPlayer);
                engine.makeMove(x, y, letter, word);
                view->showMessage("Słowo dodane do słownika!");
            } else {
                view->showMessage("Słowo odrzucone. Tracisz kolejkę!");
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;

            std::cout << "Wpisz dowolny znak i naciśnij Enter, aby kontynuować... ";
            std::cin >> temp;
        }
    }

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