#include "Food.h"
#include "MacUILib.h"
 
 
Food::Food(){
 
    srand(time(NULL));
 
    objPos tempPos, tempPos_1, tempPos_2, tempPos_3, tempPos_4;
    tempPos.setObjPos(-1, -1, 'o');
    tempPos_1.setObjPos(-2, -2, 'o');
    tempPos_2.setObjPos(-3, -3, 'o');
    tempPos_3.setObjPos(-4, -4, 'o');
    tempPos_4.setObjPos(-5, -5, '$');
    foodBucket = new objPosArrayList();
    foodBucket->insertHead(tempPos);
    foodBucket->insertHead(tempPos_1);
    foodBucket->insertHead(tempPos_2);
    foodBucket->insertHead(tempPos_3);
    foodBucket->insertHead(tempPos_4);
 
}
 
Food::~Food()
{
    // delete any heap members here
    //leave empty for iteration 1 since you don't need it yet
    delete foodBucket;
}
 
void Food::generateFood(objPosArrayList* blockOff){
    //generate random x and y cord, make sure they are not border or blockoff
 
    // check x and y against 0 and boardSize/Y
 
    int i = 0;
    int count = 0;
    int x1;
    int y1;
 
    while(count < 5){
        int flag = 0;
        
        if(count < 4){
            x1 = (rand() %18)+1;
            y1 =(rand() %8) +1;
 
            objPos tempPos_1(x1, y1, 'o');
 
            for(int i = 0; i < blockOff->getSize(); i++){
 
                objPos a;
                blockOff->getElement(a, i);
 
                if(tempPos_1.isPosEqual(&a)){
                    flag = 1;
 
                }
            }

            for(int j = 0; j <count; j++){
 
                objPos a;
                foodBucket->getElement(a, j);
 
                if(tempPos_1.isPosEqual(&a)){
                    flag = 1;
 
                }
            }

            if(flag ==0){
                foodBucket->removeTail();
                foodBucket->insertHead(tempPos_1);
                count++;
                }
        }
        
        if(count == 4){
            x1 = (rand() %18)+1;
            y1 =(rand() %8) +1;
 
            objPos tempPos_1(x1, y1, '$');
 
            for(int i = 0; i < blockOff->getSize(); i++){
 
                objPos a;
                blockOff->getElement(a, i);
 
                if(tempPos_1.isPosEqual(&a)){
                    flag = 1;
 
                }
            }

            for(int j = 0; j <count; j++){
 
                objPos a;
                foodBucket->getElement(a, j);
 
                if(tempPos_1.isPosEqual(&a)){
                    flag = 1;
 
                }
            }

            if(flag ==0){
                foodBucket->removeTail();
                foodBucket->insertHead(tempPos_1);
                count++;
                }
            }
        }
    }
 
   
 
 

 
 
 

objPosArrayList* Food::getFoodPos(){
 
    /*
    for(int i = 0; i<3; i++){
    objPos tempPos;
    foodBucket->getElement(tempPos, i);
   
    returnPos.setObjPos(tempPos.x, tempPos.y, tempPos.symbol);
    }
    */
   return foodBucket;
 
}


