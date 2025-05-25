#pragma once

#include "SecondLogic.h"
#include <windows.h>
#include <ctime>

bool CheckWin(char playerChar) {
    for (int i = 0; i < 3; ++i) {
        if (common.GameMap[i][0] == playerChar &&
            common.GameMap[i][1] == playerChar &&
            common.GameMap[i][2] == playerChar) {
            return true;
        }
    }

    for (int j = 0; j < 3; ++j) {
        if (common.GameMap[0][j] == playerChar &&
            common.GameMap[1][j] == playerChar &&
            common.GameMap[2][j] == playerChar) {
            return true;
        }
    }

    if (common.GameMap[0][0] == playerChar &&
        common.GameMap[1][1] == playerChar &&
        common.GameMap[2][2] == playerChar) {
        return true;
    }

    if (common.GameMap[0][2] == playerChar &&
        common.GameMap[1][1] == playerChar &&
        common.GameMap[2][0] == playerChar) {
        return true;
    }

    return false;
}

void Draw() {
    for (int i = 0; i < 3; ++i) {
        std::cout << i << "  ";
        for (int j = 0; j < 3; ++j) {
            std::cout << common.GameMap[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

int StandSigns(int& choiceRows, int& choiceCols) {
    srand(time(0));

    if (common.player && common.GameMap[choiceRows][choiceCols] == '.') {
        common.GameMap[choiceRows][choiceCols] = 'o';
    }
    else if (!common.player && common.GameMap[choiceRows][choiceCols] == '.') {
        common.GameMap[choiceRows][choiceCols] = 'x';
    }
    else {
        return -1;
    }

    do {
        common.botChoiceRows = rand() % 3;
        common.botChoiceCols = rand() % 3;
    } while (common.GameMap[common.botChoiceRows][common.botChoiceCols] != '.');

    if (common.player) {
        common.GameMap[common.botChoiceRows][common.botChoiceCols] = 'x';
    }
    else {
        common.GameMap[common.botChoiceRows][common.botChoiceCols] = 'o';
    }

    return 0;
}

void WinOrLose() {
    system("cls");
    Draw();

    bool xWins = CheckWin('x');
    bool oWins = CheckWin('o');

    if (xWins) {
        if (common.player == common.X) {
            std::cout << "X (player) - win!\n";
        }
        else {
            std::cout << "X (bot) - win!\n";
        }
        common.isWin = true;
        common.isGaming = false;
    }
    else if (oWins) {
        if (common.player == common.O) {
            std::cout << "O (player) - win!\n";
        }
        else {
            std::cout << "O (bot) - win!\n";
        }
        common.isWin = true;
        common.isGaming = false;
    }
}

void MainGame() {
    if (common.player)
        std::cout << "You are playing for O\n";
    else
        std::cout << "You are playing for X\n";

    while (common.isGaming) {
        system("cls");
        Draw();

        std::cout << "Input Row and Column (0-2): ";
        std::cin >> common.choiceRows >> common.choiceCols;

        if (common.choiceRows < 0 || common.choiceRows > 2 ||
            common.choiceCols < 0 || common.choiceCols > 2) {
            std::cout << "Invalid input! Try again.\n";
            Sleep(1000);
            continue;
        }

        if (StandSigns(common.choiceRows, common.choiceCols)) {
            std::cout << "Invalid move! Try again.\n";
            Sleep(1000);
            continue;
        }
        WinOrLose();
    }
}