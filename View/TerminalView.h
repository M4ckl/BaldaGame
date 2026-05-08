#ifndef BALDAGAME_TERMINALVIEW_H
#define BALDAGAME_TERMINALVIEW_H

#include "IView.h"
#include "../Model/Board.h"

class TerminalView : public IView {
private:
    void clear();

public:
    void drawBoard(const Board& b) override;
    void showMessage(const std::string& msg) override;
    void requestMove(int& x, int& y, char& letter, std::string& word) override;
    bool askConfirmation(const std::string& word) override;
};


#endif