#include "Controller/GameController.h"
#include "View/TerminalView.h"

int main() {
    TerminalView view;
    GameController controller(&view);
    controller.play();

    return 0;
}