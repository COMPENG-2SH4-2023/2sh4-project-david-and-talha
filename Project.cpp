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
objPosArrayList* block;
 
 
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

    //New food, GameMechs and Player classes

    myGM = new GameMechs(26, 13);
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);
   
    //Iteration border object creation:
 
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
 
    //Blocking off intial player position
    block = new objPosArrayList(); // remove this after finishing code and replace it
    objPos blk_player(myGM->getBoardSizeX()/2, myGM->getBoardSizeY()/2,'*');
    block->insertHead(blk_player);
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
    bool drawn_1;
 
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
   
    objPosArrayList* foodplace = myFood->getFoodPos();
    objPos tempBody_1;
 
 
    for(int y = 0;y<myGM->getBoardSizeY(); y++){
       
        for(int x=0;x<myGM->getBoardSizeX();x++){
             
            //drawing player

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

            //Drawing food
            
            drawn_1 = false;
           
            for(int q = 0;q < foodplace->getSize(); q++){


                foodplace->getElement(tempBody_1, q);
                if(tempBody_1.x == x && tempBody_1.y == y){
                    MacUILib_printf("%c", tempBody_1.symbol);
                    drawn_1 = true;
                    break;
                }
 
            }
 
            if(drawn_1) continue;

            //Drawing border           
           
            if(y==0 || x==0 || x == myGM->getBoardSizeX()-1 || y==myGM->getBoardSizeY()-1){
                MacUILib_printf("%c", border[y][x].symbol);
                continue;
            }
           
            else {
                MacUILib_printf(" ");
            }
 
            }
            MacUILib_printf("\n");
 
           
   
        }
 
        //
   
 
    MacUILib_printf("\nScore is %i\n", myGM->getScore());
    MacUILib_printf("$ is speacial food that increases snake size by 2 and adds 10 to the score\n");
    MacUILib_printf("Press z to quit game\n");
    MacUILib_printf("Snake lenght is %i\n", playerBody->getSize());
    
 
 
}
 
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

 
 
void CleanUp(void)
{
    MacUILib_clearScreen();
   
    //failed and quit flags

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
    delete block;
    
 
}