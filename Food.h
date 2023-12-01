#ifndef FOOD_H
#define FOOD_H
 
#include <cstdlib>
#include <time.h>
 
#include "objPos.h"
#include "objPosArrayList.h"
 
using namespace std;
 
 
class Food
{
    private:
 
    objPosArrayList* foodBucket;
 
    public:
 
    Food();
    ~Food();
 
    //need to accept player body array list
    //go thorugh each array element to make sure they are
    //blocked of from random food generation
    void generateFood(objPosArrayList* blockOff); //You'll need to upgrade this somehow
    objPosArrayList* getFoodPos();
 
};
 
#endif
