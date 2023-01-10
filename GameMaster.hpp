#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include <iostream>

#include "Board.hpp"
#include "Player.hpp"
#include "AI.hpp"

class GameMaster
{
private:
    char gameStatus = '1';
    int gameType = 0;

public:
    // Prints the salutations message.
    static void greetings();

    // Sets the game type based on user input (1 - Player vs Player, 2 - Player vs Random Computer, 3 - Player vs Genius Computer).
    void setGameType();

    // Returns the game type (1 - Player vs Player, 2 - Player vs Random Computer, 3 - Player vs Genius Computer).
    int getGameType();

    // Sets the game status using setTheGameStatus() class method, prints appropiate message regarding current game status and possibly terminating the game by invoking gameOver() method.
    void checkTheGameStatus(Board board);

    // Sets the game status (1 for ongoing game, D for draw, O for player1 win, X for player2 win) by checking if the game is ongoing based on the Board methods (in provided order): getGameStatusForDiagonals(), getGameStatusForRowsAndCols(), isThereFreeField() (for draw).
    // Beware: this function is not a typical setter. It's automated.
    void setTheGameStatus(Board board);

    // Returns a game status (1 for ongoing game, D for draw, O for player1 win, X for player2 win).
    char getTheGameStatus();

    // Prints the message about the end of the game, pausing the game waiting for user input, and exiting the program by using exit() function.
    void gameOver();
};

#endif