/* Author: Grace Swartz (2414391, gswartz@chapman.edu) */
/* PA 2: Mario */
/* Class: CPSC350-02 */
/* Date: 9/24/24 */
/* Summary: 
    - defines mario class which holds methods for mario's gameplay and interaction with the environment
    - declares variables to keep track of mario's stats (power level, life count, coin count, game level, enemies defeated) */

#ifndef MARIO_H
#define MARIO_H
#include <string>
#include <cstdlib>
#include <ctime>


class Mario {
public:
    Mario(); // constructor for mario's status at the start of the game
    Mario(unsigned int lifeCount); // overloaded constructor that holds mario's life count
    virtual~Mario(); // destructor

    std::string gainPower(); // for when mario goes up a power level
    std::string losePower(); // for when mario goes down a power level
    std::string encounterCoin(); // for when mario encounters a coin
    std::string encounterGoomba(); // for when mario encounters a goomba
    std::string encounterKoopa();  // for when mario encounters a koopa
    std::string encounterBoss(); // for when mario encounters a boss

    void encounterPipe(); // for when mario encounters a pipe -- he automatically levels up
    void levelUp(); // for when mario levels up -- this function moves him there

    int currentPower; // keeps track of mario's current power level
    int lifeCount; // keeps track of mario's life count
    unsigned int coinCount; // mario's wallet -- keeps count of his coins

    bool levelPlay; // boolean for mario's status (alive, dead, on/off pipe) -- used for when mario levels up (automatically set to true, meaning his is in his current level)
    static int gameLevelCount; // keeps track of the level mario is on -- is static so it can be used throughout program

private:
    int enemiesDefeated; // private counter of the enemies that mario defeats
};
#endif