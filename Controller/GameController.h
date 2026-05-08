#ifndef BALDAGAME_GAMECONTROLLER_H
#define BALDAGAME_GAMECONTROLLER_H
#include "../Model/Engine.h"
#include "../View/IView.h"

class GameController {
private:
    Engine engine;
    IView* view;
    int currentPlayer;

public:
    GameController(IView* viewInterface);

    void play();
};


#endif