## Table of contents
* [General info](#general-info)
* [Course of the game](#course-of-the-game)
* [Technologies](#technologies) 


## General info
This program is a command window game - cross checkers.
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

Program features:
* allow two people play the game,
* show help (game descripion and game rules),
* allow figures to move,
* automaticly check possible capture and force it,
* automaticly check win condiion,
* have friendly user interface,

Game board:
```
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

## Course of the game

#### When we launch a game, it asks us to give players name
![player names](/img/playernames.png)

#### After giving players name's program shows us menu, where we can choose
#### 1 - play, 2 - help, 3 - exit
![menu](/img/menu.png)

#### Help option describes game rules and how to play the game
![help](/img/help.png)

#### Play option launches game, turn indicator appears on screen
![turnindication](/img/turnindication.png)

#### After pressing ENTER game board appears on screen,
#### on the right there are turn indicator and wind rose.
#### Player is requested to choose figure by giving it coordinates
![figurepick](/img/figurepick.png)

#### After picking figure player has to options, to move choosen figure or pick another one
![figuredecision](/img/figuredecision.png)

#### When we decide to move choosen figure, we are asked about in which direction we want to move
![wheretomove](/img/wheretomove.png)


#### When there is possible capture for player, program detect it, and force player to do it by pressing ENTER
![forcecapture](/img/forcecapture.png)

#### Game ends when program detects one of the winning condition.

## Technologies
Project is created with:
* C++ 17,
* basic c++ libraries (iostream, iomanip, windows.h),
