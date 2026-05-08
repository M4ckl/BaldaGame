#ifndef BALDAGAME_IVIEW_H
#define BALDAGAME_IVIEW_H

#include <string>
#include "../Model/Board.h"

class IView {
public:
    virtual ~IView() = default;

    virtual void drawBoard(const Board& b) = 0;
    virtual void showMessage(const std::string& msg) = 0;

    virtual void requestMove(int& x, int& y, char& letter, std::string& word) = 0;

    virtual bool askConfirmation(const std::string& word) = 0;
};

#endif