#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"
 
//Global variables defined here
 
objPos** border;
objPos* list;
 
 
 
 
 
 
using namespace std;
 
#define DELAY_CONST 100000
 
GameMechs* myGM;
Player* myPlayer;
 
Food* myFood;
 
 
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
 
 
 
int main(void)
{
 
    Initialize();
 
    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
 
    CleanUp();
 
}
 
 
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
 
    myGM = new GameMechs(26, 13);
   
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);
   
    //Iteration 0 stuff:
 
    border = new objPos*[myGM->getBoardSizeY()];
 
    for(int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        border[i] = new objPos[myGM->getBoardSizeX()];
    }
   
 
    for(int i = 0; i < myGM->getBoardSizeY(); i++) {
        for(int j = 0; j < myGM->getBoardSizeX(); j++) {
            border[i][j] = objPos(j, i, '#');
    }
       
    }
 
    list = new objPos[5];
 
    for(int i = 0; i <5; i++){
        list[i] = objPos(i+2,i+2,'.');
    }
 
    //Iteration 2
 
    objPosArrayList block; // remove this after finishing code and replace it
    myFood->generateFood(block);
   
}
   
 
 
 
void GetInput(void)
{
   
    myGM->getInput();
   
}
 
void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();
   
 
 
}
 
//Seed Random number generator in game mechanics
 
void DrawScreen(void)
{
    MacUILib_clearScreen();
 
    bool drawn;
 
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
   
    objPos foodplace;
    myFood->getFoodPos(foodplace);
 
 
    for(int y = 0;y<myGM->getBoardSizeY(); y++){
       
        for(int x=0;x<myGM->getBoardSizeX();x++){
 
            drawn = false;
           
            for(int k = 0;k < playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);
                if(tempBody.x == x && tempBody.y == y){
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
 
            }
 
            if(drawn) continue;
           
            if(y==0 || x==0 || x == myGM->getBoardSizeX()-1 || y==myGM->getBoardSizeY()-1){
                MacUILib_printf("%c", border[y][x].symbol);
                continue;
            }
            /*
            else if(y == tempPos.y && x == tempPos.x){
                printf("%c", tempPos.symbol);
            }
            */
            else if(y == foodplace.y && x == foodplace.x){
                printf("%c", foodplace.symbol);
            }
           
            else {
                MacUILib_printf(" ");
            }
 
            }
            MacUILib_printf("\n");
 
           
   
        }
 
        //
   
 
    MacUILib_printf("\nScore is %i\n", myGM->getScore());
 
    MacUILib_printf("Player Position:\n");
    for(int l = 0; l < playerBody->getSize(); l++)
    {
        playerBody->getElement(tempBody, l);
        MacUILib_printf("<%d, %d>", tempBody.x, tempBody.y);
    }
 
 
 
   
   
 
}
 
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}
 
 
void CleanUp(void)
{
    MacUILib_clearScreen();
   
    if(myGM->getLoseFlagStatus()){
        MacUILib_printf("\nYOU FAILED!!!!!");
    } else{
        MacUILib_printf("\nYOU QUIT!!!!!");
    }
 
 
   
 
    MacUILib_uninit();
 
    //remove heap instances
    delete myGM;
    delete myPlayer;
    delete myFood;
 
 
}
 