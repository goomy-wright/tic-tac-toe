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

bool Table::setValue(const char row, const std::string value, const int num)
{
    if (num > 3 && num < 1) return false;

    switch (row) {
    case 'a':
        if (this->fields[0][num - 1] != this->none) return false;
        
        this->fields[0][num - 1] = value;
        break;
    case 'b':
        if (this->fields[1][num - 1] != this->none) return false;
        
        this->fields[1][num - 1] = value;
        break;
    case 'c':
        if (this->fields[2][num - 1] != this->none) return false;
        
        this->fields[2][num - 1] = value;
        break;
    default:
        return false;
    }

    return true;
}

std::string Table::checkWin()
{
    for (int i = 0; i < 3; ++i) {
        if (this->fields[i][0] == this->fields[i][1] && this->fields[i][0] == this->fields[i][2] && this->fields[i][0] != this->none) {
            return this->fields[i][0];
        }

        if (this->fields[0][i] == this->fields[1][i] && this->fields[0][i] == this->fields[2][i] && this->fields[0][i] != this->none) {
            return this->fields[0][i];
        }
    }

    if (this->fields[0][0] == this->fields[1][1] && this->fields[2][2] == this->fields[0][0] && this->fields[0][0] != this->none) {
        return this->fields[0][0];
    } else if (this->fields[0][2] == this->fields[1][1] && this->fields[2][0] == this->fields[0][2] && this->fields[0][2] != this->none) {
        return this->fields[0][2];
    }

    if (this->fields[0][0] != this->none && this->fields[0][1] != this->none && this->fields[0][2] != this->none) {
        if (this->fields[1][0] != this->none && this->fields[1][1] != this->none && this->fields[1][2] != this->none) {
            if (this->fields[2][0] != this->none && this->fields[2][1] != this->none && this->fields[2][2] != this->none) {
                this->outOfFields = true;
            }
        }
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
        if (this->t.outOfFields) {
            std::cout << "Draw!" << std::endl;
            this->t.print();
            exit(1);
        }

        this->t.print();
        
        if (this->playerOTurn) std::cout << this->playerO << " [o]: ";
        else std::cout << this->playerX << " [x]: ";

        std::cin >> this->charInput >> this->intInput;
        
        if (!this->playerOTurn) this->testSetValue = this->t.setValue(this->charInput, "x", this->intInput);
        else this->testSetValue = this->t.setValue(this->charInput, "o", this->intInput); 

        if (this->testSetValue) {
            std::string check = this->t.checkWin();
            if (check != " ") {
                if (check == "x") std::cout << this->playerX << " win!" << std::endl;
                else std::cout << this->playerO << " win!" << std::endl;
                this->t.print();
                
                exit(1);
            }

            if (this->playerOTurn) this->playerOTurn = false;
            else this->playerOTurn = true;
        } else {
            std::cout << "Field already used!Or invalid option!" << std::endl;
        }
    }
}