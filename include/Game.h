#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Table
{
private:
    std::string none = " ";
    std::vector<std::vector<std::string>> fields{
        {none, none, none},
        {none, none, none},
        {none, none, none},
    };

    std::vector<char> borders{
        '-', '|', '+'
    };

public:
    void
        print(),
        setValue(const char row, const std::string value, const int num);
    
    std::string checkWin();
};

class TicTacToe
{
private:
    std::string
        playerX,
        playerO;

    bool playerOTurn = false;
    char charInput;
    int intInput;

    Table t;
public:
    TicTacToe(const std::string playerOne, const std::string playerTwo);
    ~TicTacToe() { delete this; };

    void
        start();
};

#endif // GAME_H