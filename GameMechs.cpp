#include "GameMechs.h"
#include "MacUILib.h"
 
GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
    score = 0;
    loseFlag = false;
}
 
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
    loseFlag = false;
}
 
// do you need a destructor?
 
 
 
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}
 
char GameMechs::getInput()
{
    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
        if(input == 'z'){
        GameMechs:setExitTrue();
    }
    }
    return input;
}
 
int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}
 
int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}
 
 
void GameMechs::setExitTrue()
{
    exitFlag = true;
}
 
void GameMechs::setInput(char this_input)
{
    input = this_input;
}
 
void GameMechs::clearInput()
{
    input = 0;
}
 
void GameMechs::incrementScore()
{
    score++;
}
 
int GameMechs::getScore()
{
    return score;
}
 
bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}
void GameMechs::setLoseFlag()
{
   
    loseFlag = true;
   
}