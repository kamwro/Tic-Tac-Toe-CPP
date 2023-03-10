#include "GameMaster.hpp"
#include "Board.hpp"

void GameMaster::greetings()
{
    std::cout << "Welcome to the Tic Tac Toe game! This is a two player game without the AI or the player vs AI mode. You choose.\n\n";
}

void GameMaster::setGameType()
{
    int choice = 0;
    while (choice != 1 && choice != 2 && choice != 3)
    {
        std::cout << "1. Player vs Player\n";
        std::cout << "2. Player vs Random Computer\n";
        std::cout << "3. Player vs Smart Computer\n";
        std::cin >> choice;
        std::cout << std::endl;
    }
    gameType = choice;
}

int GameMaster::getGameType()
{
    return gameType;
}
void GameMaster::checkTheGameStatus(Board board, char player1Name, char player2Name)
{
    evaluateTheGameStatus(board);
    if (gameStatus == '0')
    {
        std::cout << "Draw! Nobody wins.\n";
    }
    else if (gameStatus == player1Name)
    {
        std::cout << "Player 1 wins!\n";
    }
    else if (gameStatus == player2Name)
    {
        std::cout << "Player 2 wins!\n";
    }
    if (gameStatus == '1')
    {
        std::cout << "Next turn.\n";
    }
    else
        gameOver();
}

void GameMaster::evaluateTheGameStatus(Board board)
{
    gameStatus = board.getGameStatusForDiagonals();
    if (gameStatus == '1')
        gameStatus = board.getGameStatusForRowsAndCols();
    if (gameStatus == '1')
    {
        if (board.isThereFreeField())
            gameStatus = '1';
        else
            gameStatus = '0';
    }
}

char GameMaster::getTheGameStatus()
{
    return gameStatus;
}

void GameMaster::gameOver()
{
    std::cout << "Game Over! Type anything to continue...\n";
    char c;
    std::cin >> c;
    exit(1);
}
