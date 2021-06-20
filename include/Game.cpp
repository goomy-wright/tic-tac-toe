#include <iostream>
#include "Game.h"

void Table::print()
{
    std::cout << this->fields[0][0] << this->borders[1] << this->fields[0][1] << this->borders[1] << this->fields[0][2] << std::endl;
    std::cout << this->borders[0] << this->borders[2] << this->borders[0] << this->borders[2] << this->borders[0] << std::endl;
    std::cout << this->fields[1][0] << this->borders[1] << this->fields[1][1] << this->borders[1] << this->fields[1][2] << std::endl;
    std::cout << this->borders[0] << this->borders[2] << this->borders[0] << this->borders[2] << this->borders[0] << std::endl;
    std::cout << this->fields[2][0] << this->borders[1] << this->fields[2][1] << this->borders[1] << this->fields[2][2] << std::endl;
}

void Table::setValue(const char row, const std::string value, const int num)
{
    switch (row) {
    case 'a':
        this->fields[0][num - 1] = value;
        break;
    case 'b':
        this->fields[1][num - 1] = value;
        break;
    case 'c':
        this->fields[2][num - 1] = value;
        break;
    }
}

std::string Table::checkWin()
{
    for (int i = 0; i < 3; ++i) {
        if (this->fields[i][0] == this->fields[i][1] && this->fields[i][0] == this->fields[i][2] && this->fields[i][0] != this->none) {
            return this->fields[i][0];
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (this->fields[0][i] == this->fields[1][i] && this->fields[0][i] == this->fields[2][i] && this->fields[0][i] != this->none) {
            return this->fields[0][i];
        }
    }

    if (this->fields[0][0] == this->fields[1][1] && this->fields[2][2] == this->fields[0][0] && this->fields[0][0] != this->none) {
        return this->fields[0][0];
    } else if (this->fields[0][2] == this->fields[1][1] && this->fields[2][0] == this->fields[0][2] && this->fields[0][2] != this->none) {
        return this->fields[0][2];
    }

    return this->none;
}

TicTacToe::TicTacToe(const std::string playerOne, const std::string playerTwo)
{
    this->playerX = playerOne;
    this->playerO = playerTwo;
}

void TicTacToe::start()
{
    while (1) {
        this->t.print();
        if (this->playerOTurn) std::cout << this->playerO << " [o]: ";
        else std::cout << this->playerX << " [x]: ";

        std::cin >> this->charInput >> this->intInput;
        
        if (!this->playerOTurn) this->t.setValue(this->charInput, "x", this->intInput);
        else this->t.setValue(this->charInput, "o", this->intInput);

        std::string check = this->t.checkWin();
        if (check != " ") {
            if (check == "x") std::cout << this->playerX << " win!" << std::endl;
            else std::cout << this->playerO << " win!" << std::endl;
            exit(1);
        }

        if (this->playerOTurn) this->playerOTurn = false;
        else this->playerOTurn = true;
    }
}