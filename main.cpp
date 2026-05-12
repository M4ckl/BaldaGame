#include "Controller/GameController.h"
#include "View/TerminalView.h"

int main() {
    // 1. Создаем конкретное представление (View)
    TerminalView view;

    // 2. Создаем контроллер и передаем ему ссылку на представление (Dependency Injection)
    GameController controller(&view);

    // 3. Запускаем игру
    controller.play();

    return 0;
}