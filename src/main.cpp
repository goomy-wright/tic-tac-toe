#include <iostream>
#include "../include/Game.cpp"

int main(int argc, const char *argv[]) {
    TicTacToe game("Player One", "Player Two");
    game.start();
}
