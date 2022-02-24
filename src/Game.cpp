#include <Game.h>

void Table::print()
{
    std::cout << std::endl;
    std::cout << this->fields[0] << this->borders[1] << this->fields[1] << this->borders[1] << this->fields[2] << std::endl;
    std::cout << this->borders[0] << this->borders[2] << this->borders[0] << this->borders[2] << this->borders[0] << std::endl;
    std::cout << this->fields[3] << this->borders[1] << this->fields[4] << this->borders[1] << this->fields[5] << std::endl;
    std::cout << this->borders[0] << this->borders[2] << this->borders[0] << this->borders[2] << this->borders[0] << std::endl;
    std::cout << this->fields[6] << this->borders[1] << this->fields[7] << this->borders[1] << this->fields[8] << std::endl;
}

bool Table::setValue(const char value, const int num)
{
    if (num > 9 && num < 1) return false;
    if (this->fields[num - 1] != this->none) return false;
    
    this->fields[num - 1] = value;
    return true;
}

char Table::checkWin()
{
    for (int i = 0; i < 9; ++i)
    {
        if (this->fields[i] == this->none)
        {
            this->outOfFields = false;
            break;
        }
        else
            this->outOfFields = true;
    }

    if (this->fields[0] == this->fields[1] && this->fields[0] == this->fields[2] && this->fields[0] != this->none)
        return this->fields[0];
    else if (this->fields[3] == this->fields[4] && this->fields[3] == this->fields[5] && this->fields[3] != this->none)
        return this->fields[3];
    else if (this->fields[6] == this->fields[7] && this->fields[6] == this->fields[8] && this->fields[6] != this->none)
        return this->fields[6];

    if (this->fields[0] == this->fields[3] && this->fields[0] == this->fields[6] && this->fields[0] != this->none)
        return this->fields[0];
    else if (this->fields[1] == this->fields[4] && this->fields[1] == this->fields[7] && this->fields[1] != this->none)
        return this->fields[1];
    else if (this->fields[2] == this->fields[5] && this->fields[2] == this->fields[8] && this->fields[2] != this->none)
        return this->fields[2];

    if (this->fields[0] == this->fields[4] && this->fields[0] == this->fields[8] && this->fields[0] != this->none)
        return this->fields[0];
    else if (this->fields[2] == this->fields[4] && this->fields[2] == this->fields[6] && this->fields[2] != this->none)
        return this->fields[2];

    return this->none;
}

TicTacToe::TicTacToe()
{
    std::cout << "X Player Name: ";
    std::cin >> this->playerX;

    std::cout << "O Player Name: ";
    std::cin >> this->playerO; 
}

void TicTacToe::start()
{
    while (1) {
        if (this->t.outOfFields) {
            this->t.print();
            std::cout << "Draw!" << std::endl;
            break;
        }

        this->t.print();
        
        if (this->playerOTurn) std::cout << this->playerO << " [o]: ";
        else std::cout << this->playerX << " [x]: ";

        std::cin >> this->fieldInput;
        
        if (!this->playerOTurn) this->testSetValue = this->t.setValue('x', this->fieldInput);
        else this->testSetValue = this->t.setValue('o', this->fieldInput); 

        if (this->testSetValue) {
            char check = this->t.checkWin();
            if (check != ' ') {
                this->t.print();

                if (check == 'x')
                    std::cout << this->playerX << " win!" << std::endl;
                else
                    std::cout << this->playerO << " win!" << std::endl;
    
                break;
            }

            if (this->playerOTurn) this->playerOTurn = false;
            else this->playerOTurn = true;
        } else {
            std::cout << "Field already used, or invalid option!" << std::endl;
        }
    }
}