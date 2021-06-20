# Tic Tac Toe Mini Console Game in C++
## Include Library
```cpp
#include "path/to/include/Game.cpp"
```

## Start the Game
```cpp
int main(int argc, const char *argv[]) {
    TicTacToe game("Player One", "Player Two");
    game.start();
}
```

## How to Play
* First input (a, b, c) - row
* Second input (1, 2, 3) - number of field

## Examples
```
 | | 
-+-+-
 | | 
-+-+-
 | | 
Player One [x]: a 1

x| | 
-+-+-
 | | 
-+-+-
 | | 
Player Two [o]: c 3

x| | 
-+-+-
 | | 
-+-+-
 | |o
```