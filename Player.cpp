#include "Player.h"
 
 
Player::Player(GameMechs* thisGMRef,Food* FoodRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    FoodReference = FoodRef;
 
 
    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
 
 
    //playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,);
    playerPosList = new objPosArrayList();
   
 
   
   
 
   
 
 
    playerPosList->insertHead(tempPos);
   
 
   
 
}
 
 
Player::~Player()
{
    // delete any heap members here
    //leave empty for iteration 1 since you don't need it yet
    delete playerPosList;
}
 
objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}
 
void Player::updatePlayerDir()
{
    // PPA3 input processing logic
 
    //Work for David: where are you supposed to get the input? How to check input?
 
    char input = mainGameMechsRef->getInput();
 
 
 
    switch(input)
    {
        case 'w':
            if(myDir == RIGHT || myDir == LEFT || myDir == STOP){
            myDir = UP;
            }
            break;
 
        case 's':
            if(myDir == RIGHT || myDir == LEFT || myDir == STOP){
            myDir = DOWN;
            }
            break;
 
        case 'd':
            if(myDir == UP || myDir == DOWN || myDir == STOP){
            myDir = RIGHT;
            }
            break;
 
        case 'a':
            if(myDir == UP || myDir == DOWN || myDir == STOP){
            myDir = LEFT;
            }
            break;
        default:
            break;
    }      
}
 
void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
 
    int bY = mainGameMechsRef->getBoardSizeY();
    int bX = mainGameMechsRef->getBoardSizeX();
 
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);
 
 
    switch(myDir){
        case UP:
            if(currentHead.y == 1){
                currentHead.y =  bY - 2;
            } else {
                currentHead.y--;
            }
            break;
 
        case DOWN:
            if(currentHead.y == bY -2){
                currentHead.y = 1;
            } else {
                currentHead.y++;
            }
            break;
 
        case RIGHT:
            if(currentHead.x == bX -2){
                currentHead.x = 1;
            } else{
                currentHead.x++;
            }
            break;
 
        case LEFT:
            if(currentHead.x == 1){
                currentHead.x = bX -2;
            } else{
                currentHead.x--;
            }
            break;
 
        default:
            break;
    }
 
    playerPosList->insertHead(currentHead);
 
    objPosArrayList* FoodEat = FoodReference->getFoodPos();
    objPos a;
    int flag = 0;
    int growthbonusflag = 0;
 
 
    
    if(checkFoodCollision() == 1 || checkFoodCollision() == 2){
        if(checkFoodCollision() ==2){ //checks if special food was eaten
            for(int v = 0; v<9; v++){
                mainGameMechsRef->incrementScore(); 
                }
            for(int v = 0; v<2; v++){
                playerPosList->insertHead(currentHead);
                growthbonusflag = 1;
                }
            }
        mainGameMechsRef->incrementScore();
        FoodReference->generateFood(playerPosList);
        flag = 1;
    }        
 
    if(flag == 0 || growthbonusflag == 1){
        playerPosList->removeTail();
    }

    if(growthbonusflag == 0){
        checkSelfCollision();
    }
    
 
       
       
 
   
   
 
 
 
 
   
}

int Player::checkFoodCollision(){

    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    objPosArrayList* FoodEat = FoodReference->getFoodPos();
    objPos a;

    for(int i = 0; i< FoodEat->getSize(); i++){
        FoodEat->getElement(a, i);
        if(currentHead.isPosEqual(&a)){
            if(a.getSymbol() == '$'){
                return 2;
            }
            else{
                return 1;
                }
            
            }
    }

}
 
bool Player::checkSelfCollision(){
 
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);
 
    for(int i = 1; i< playerPosList->getSize(); i++){
        objPos body[i];
        playerPosList->getElement(body[i], i);
        if(currentHead.isPosEqual(&body[i]) && myDir != STOP){
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
 
    }
 
}


