## Table of contents
* [General info](#general-info)
* [Technologies](#technologies) 


## General info
This is my university project, my task was to do cross checkers board game in command window.

### Task from university
```
Cross checkers board game is made for two players.
There is 49 squares on the board, 16 figures 'o' and 16 figures 'x'.
Players move in turns, player with 'x' figures begins.
In each turn player need to move one figure in possible moves:
* figures 'o', 'x' can move by one square  along the drawn lines on the board ('-', '|', '/', '\'),
* figures 'o', 'x' can capture enemy figures along the drawn lines on the board ('-', '|', '/', '\'),
  square behind captured figure must be empty,
  
After the capture, captured figure is taken out of the board. Capture is forced. Multiple capture is possible.
Player wins if his enemy can't do any move or if he capture all enemy figures.
Also player wins if he reach opposite end of the board with his figure.

Program should:
* allow two people play the game,
* show help (game descripion and game rules),
* allow figures to move, force captures,
* automaticly check win condiion,
* have friendly user interface,

Game board:
  1 2 3 4 5 6 7 8 9
I     x---x---x     I
       \  |  /
H       x-x-x       H
         \|/   
G     x-x-x-x-x     G 
  |\  |\|/|\|/|  /|
F |   x-x-x-x-x   | F
  | |\|/|\|/|\|/| | 
E  - - - - - - - -  E
  | |/|\|/|\|/|\| | 
D |   o-o-o-o-o   | D
  |/  |/|\|/|\|  \|
C     o-o-o-o-o     C 
         /|\
B       o-o-o       B 
       /  |  \ 
A     o---o---o
  1 2 3 4 5 6 7 8 9	   
```

## Technologies
Project is created with:
* C++ 17,
* basic c++ libraries (iostream, iomanip, windows.h),