## Table of contents
* [General info](#general-info)
* [Course of the game](#course-of-the-game)
* [Project status](#project-status) 


## General info
This program is a CLI board game for two players - cross checkers.
Game board consist of 49 squares, 16 figures 'o' and 16 figures 'x'.
Players move in turns, in each turn player can move one of his figure in following ways:
* figures can move by one square along the drawn lines on the board ('-', '|', '/', '\'),
* figures can capture enemy figures along the drawn lines on the board ('-', '|', '/', '\'),
  square behind captured figure has to empty,
  
Capture is automaticly detected and forced for player to do it.
Player wins if his enemy can't do any move or if he has captured all enemy figures.
Also player wins if he has reached opposite end of the board with his figure.


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
![forcedcapture](/img/forcedcapture.png)

#### Game ends when program detects one of the winning condition.

## Project status
### unfinished
#### TO DO:
*translate code to english,