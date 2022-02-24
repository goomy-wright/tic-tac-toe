# Tic Tac Toe Mini Console Game in C++
## Include Library
```cpp
#include "path/to/include/Game.h"
```

## Start the Game
```cpp
int main(int argc, const char *argv[])
{
    TicTacToe game;
    game.start();
}
```

## Build and run the project (only on linux)
```bash
$ make && bin/app
```

## How to Play
* Input (1-9) - Field Number

## Examples
```
 | | 
-+-+-
 | | 
-+-+-
 | | 
Player One [x]: 1

x| | 
-+-+-
 | | 
-+-+-
 | | 
Player Two [o]: 9

x| | 
-+-+-
 | | 
-+-+-
 | |o
```