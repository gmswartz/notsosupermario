/* Author: Grace Swartz (2414391, gswartz@chapman.edu) */
/* PA 2: Mario */
/* Class: CPSC350-02 */
/* Date: 9/24/24 */
/* Summary: creates the makeLevel class that holds method declarations for:
    - making the level
    - displaying or printing the level
    - moving and placing mario
    - placing warp pipe 
    - and holds various variables */

#ifndef LEVEL_H
#define LEVEL_H

#include "Mario.h"
#include <iostream>
#include <cstdlib> // for random generation
#include <ctime> // for random generation
#include <string>

class makeLevel {
public:
    makeLevel(); // constructor
    makeLevel(int gridDimensions, int randCoin, int randNothing, 
    int randMushroom, int randGoomba, int randKoopa); // overloaded constructor with parameters for probability of level options
    virtual~makeLevel(); // destructor

    std::string displayLevel(); // method to print out level

    std::string moveMario(Mario* marioObj); // method to move mario and creating object to use later
    void placeMario(int gridDimensions); // method to place mario in a random place on the grid for each level
    void placeWarpPipe(); // method for placing the warp pipe in each level
    void placeBoss(); // method for placing the boss in each level

    int getLevelDimensions(); // method to get the grid dimensions of the level
private:
    int gridDimensions; // dimensions of the level (width and height)
    char** grid; // pointer to a 2D array
};
#endif