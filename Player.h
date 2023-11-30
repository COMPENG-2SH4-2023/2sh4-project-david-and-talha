#ifndef PLAYER_H
#define PLAYER_H
 
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
 
class Player
{
    // Construct the remaining declaration from the project manual.
 
    // Only some sample members are included here
 
    // You will include more data members and member functions to complete your design.
 
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
 
        Player(GameMechs* thisGMRef,Food* FoodRef);
        ~Player();
 
        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        // Need more actions in here:
        // after insterting head but before removing tail
        // - check if new head position collides with food
        // - if yes, increment the score in GM, generate new food and do not remove tail
        // otherwise remove tail and move on.
 
        //lastly add self collision check
        // if self-collided
        // set looseFlag and exitflag both true. this should break out of loop and end game
   
        // diiferntiate endgame states
        // - Lost:display LOST message
        // - otherwise display ENDGAME message
 
 
 
    private:
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.      
        enum Dir myDir;
 
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* FoodReference; //Are we allowed to add this and make changes to the player function.
       
};
 
#endif