#include "Food.h"
#include "MacUILib.h"
 
 
Food::Food(){
 
    srand(time(NULL));
    foodPos.setObjPos(-1, -1, 'o');
 
}
 
Food::~Food()
{
    // delete any heap members here
    //leave empty for iteration 1 since you don't need it yet
}
 
void Food::generateFood(objPosArrayList blockOff){
    //generate random x and y cord, make sure they are not border or blockoff
 
    // check x and y against 0 and boardSize/Y
 
    int i = 0;
    int count = 0;
    int x1;
    int y1;
 
    while(count < 1){
        int flag = 0;
        x1 = (rand() %18)+1;
        y1 =(rand() %8) +1;
 
        objPos tempPos_1(x1, y1, '*');
 
       
        for(int i = 0; i < blockOff.getSize(); i++){
 
       
        objPos a;
        blockOff.getElement(a, i);
 
        if(tempPos_1.isPosEqual(&a)){
            flag = 1;
 
        }
    }
           
       
        if(flag ==0){
            foodPos.setObjPos(x1,y1,'o');
            count++;
        }
    }
 
 
}
 
 
 
void Food::getFoodPos(objPos &returnPos){
 
   
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
 
}