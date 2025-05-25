#pragma once

#include "MainLogic.h"
#include <unordered_map>

struct CommonVariables {
    int choice, exit;
    int choiceRows, choiceCols, botChoiceRows, botChoiceCols;
    bool player, bot;

    bool X = false;
    bool O = true;

    bool isGaming = true;
    bool isWin = false;

    int countX = 0;
    int countO = 0;

    char GameMap[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };

    CommonVariables() = default;
};
CommonVariables common;

static bool EndGame(int& choice) {
    common.exit = true;
    return common.exit;
}

static bool ChoicePlayer(int& choice) {
    if (choice == 1) {
        common.player = common.O;
        common.bot = common.X;
    }
    else if (choice == 0) {
        common.player = common.X;
        common.bot = common.O;
    }
    else {
        EndGame(choice);
    }
    return common.player && common.bot;
}