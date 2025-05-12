/* Author: Grace Swartz (2414391, gswartz@chapman.edu) */
/* PA 2: Mario */
/* Class: CPSC350-02 */
/* Date: 9/24/24 */
/* Summary: creates the "world" (levels) for game
    - warp pipe and boss are placed
    - keeps track of mario's moves and when he is in each level
    - prints out status, game outcome, and number of moves */

#include "World.h"
using namespace std;

World::World() { // constructor
    levelCount = 3; // default level count is set at 3
    currentLevel = 1; // game automatically starts on the first level

    levels = new makeLevel[3]; // creating new levels array
    for (int i=0; i < levelCount; ++i) {
        levels[i] = makeLevel(); // makes default level 
    }
}

World::World(int levelCount, int gridDimensions, int randCoin, int randNothing, int randMushroom, int randGoomba, int randKoopa) { // overloaded constructor
    this->levelCount = levelCount; // assigning parameter to member variable

    currentLevel = 1;
    levels = new makeLevel[levelCount]; // reassigning size of array

    for (int i=0; i < levelCount - 1; ++i) {
        levels[i] = makeLevel(gridDimensions, randCoin, randNothing, randMushroom, randGoomba, randKoopa);
        levels[i].placeWarpPipe(); // placing the warp pipe on each level except for the last one (levelCount-1)
        levels[i].placeBoss(); // placing boss in each level (except last one)
    }
    levels[levelCount-1] = makeLevel(gridDimensions, randCoin, randNothing, randMushroom, randGoomba, randKoopa); // last level does not have a pipe
    levels[levelCount-1].placeBoss(); // placing boss in final level
}

World::~World() { // destructor
   delete[] levels; // deletes array
}

// method for gameplay
string World::playMario(int lifeCount) {
    string log = "";
    int moveCount = 0; // track of mario's total moves 
    Mario* marioObj = new Mario(lifeCount); // mario object with custom life count

    //printing the world
    for (int i=0; i<levelCount; ++i) {
        log += "Level: " + to_string(i+1);
        log += "\n" + levels[i].displayLevel() + "\n";
    }

    for (int i = 0; i<levelCount; ++i) {
        marioObj->levelPlay = true; // mario is in level, set to true when he starts a new level
        levels[i].placeMario(levels[i].getLevelDimensions()); // putting mario into the world

        while (marioObj->levelPlay) { // while mario is playing
            if (marioObj->lifeCount == 0) { // if mario is dead
                break;
            } 
            else {
                while(true) { // while mario is alive
            // printing current level
                    log += "=====================\nCurrent Level: " + to_string(i+1) + "\n" + levels[i].displayLevel();
                    log += levels[i].moveMario(marioObj);
                    moveCount++;
                    break;
                }
            }    
        }
    }
    // if mario is alive by the time he finishes the last level (he wins) 
    if (marioObj->lifeCount != 0) {
        log += "MARIO WINS! Game Over :)\n";
        log += "THE PRINCESS IS SAVED IN " + to_string(moveCount) + " MOVES!!\n";
    }
    else { // if mario loses
        log += "Gave over :( \n";
        log += "Moves taken: " + to_string(moveCount) + "\n";
    }
    delete marioObj;
    return log;
}