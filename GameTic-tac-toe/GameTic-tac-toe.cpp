#include <iostream>

#include "MainLogic.h"
#include "SecondLogic.h"

int main() {
    std::cout << "Choice your player in game: ";
    std::cin >> common.choice;
    
    system("cls");

    ChoicePlayer(common.choice);

    if (!common.exit && common.isGaming) {
        MainGame();
    }
    return 1;
}