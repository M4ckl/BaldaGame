#include "TerminalView.h"
#include <iostream>
#include <cstdlib>

void TerminalView::clear() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void TerminalView::drawBoard(const Board& b) {
    clear();
    std::cout << "=== GRA BALDA ===\n\n";
    std::cout << "  0 1 2 3 4 (X)\n";
    std::cout << "  ---------\n";

    for (int y = 0; y < 5; ++y) {
        std::cout << y << "|";
        for (int x = 0; x < 5; ++x) {
            std::cout << b.getLetter(x, y) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n(Y)\n\n";
}

void TerminalView::showMessage(const std::string& msg) {
    std::cout << ">>> " << msg << "\n";
}

void TerminalView::requestMove(int& x, int& y, char& letter, std::string& word) {
    std::cout << "Wprowadź współrzędne (X Y), literę i słowo (np. 2 1 A APPLE): ";
    std::cin >> x >> y >> letter >> word;
    letter = std::toupper(letter);
    for (char &c : word) {
        c = std::toupper(c);
    }
}

bool TerminalView::askConfirmation(const std::string& word) {
    std::cout << "Słowa '" << word << "' nie ma w słowniku.\n";
    std::cout << "Gracz 1, czy akceptujesz to słowo? (t/n): ";
    char p1;
    std::cin >> p1;

    std::cout << "Gracz 2, czy akceptujesz to słowo? (t/n): ";
    char p2;
    std::cin >> p2;

    return (p1 == 't' || p1 == 'T') && (p2 == 't' || p2 == 'T');
}