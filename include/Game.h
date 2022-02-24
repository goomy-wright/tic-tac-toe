#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Table
{
private:
    char none = ' ';
    std::vector<char>
        borders{'-', '|', '+'},
        fields{none, none, none, none, none, none, none, none, none};

public:
    bool
        setValue(const char value, const int num),
        outOfFields = false;

    void print();
    char checkWin();
};

class TicTacToe
{
public:
    std::string
        playerX,
        playerO;

    bool
        playerOTurn = false,
        testSetValue = true;

    int fieldInput;
    Table t;

    TicTacToe();
    void start();
};

#endif // GAME_H