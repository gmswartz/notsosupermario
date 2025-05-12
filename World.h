/* Author: Grace Swartz (2414391, gswartz@chapman.edu) */
/* PA 2: Mario */
/* Class: CPSC350-02 */
/* Date: 9/24/24 */
/* Summary: creates World class that holds
    - method for gameplay
    - variables for keeping track of number of levels in game and mario's current level
    - pointers used in World.cpp */

#ifndef WORLD_H
#define WORLD_H
#include <string>
#include "Level.h"

class World {
public: 
    World(); // constructor
    World(int levelCount, int gridDimensions, int randCoin, int randNothing, 
    int randMushroom, int randGoomba, int randKoopa); // overloaded constructor with parameters for probability of level options
    virtual~World(); // destructor

    std::string playMario(int lifeCount); // method to start the game and runs all rules
private:
    unsigned int levelCount; // number of levels in a world
    unsigned int currentLevel; // mario's current level
    Mario* marioObj; // pointer to an object to use in .cpp
    makeLevel* levels; // pointer to an array that holds all of level objects
};
#endif