/* Author: Grace Swartz (2414391, gswartz@chapman.edu) */
/* PA 2: Mario */
/* Class: CPSC350-02 */
/* Date: 9/24/24 */
/* Summary: 
    - defines methods for mario's gameplay (gains/loses power, levels up)
    - defines methods for when mario interacts with his environment (coin, goomba, koopa, boss, pipe) */

#include "Mario.h"
#include "Level.h"
using namespace std;

int Mario::gameLevelCount = 0; // mario starts on level "0"

Mario::Mario() { // constructor for mario's status at the start of the game 
    levelPlay = true; // boolean set to true because mario begins play in his current level
    currentPower = 0; // mario begins on PL0
    coinCount = 0; // mario begins with 0 coins
    enemiesDefeated = 0; // mario has not defeated any enemies yet
    lifeCount = 3; // mario begins with 3 lives
}

Mario::Mario(unsigned int lifeCount) { // overloaded constructor that holds mario's life count
    levelPlay = true; // boolean set to true because mario begins play in his current level
    coinCount = 0; // mario begins with 0 coins
    currentPower = 0; // mario begins on PL0
    enemiesDefeated = 0; // mario has not defeated any enemies yet 
    this->lifeCount = lifeCount; // // setting his life count--assigning the parameter to member variable
}

Mario::~Mario() {} // destructor

// method for mario gaining power
string Mario::gainPower() { 
    if (currentPower == 0) {
        currentPower = 1; // mario increases to PL1
        return "Mario is now at PL1";
    }
    else if (currentPower == 1) {
        currentPower = 2; // mario increases to PL2
        return "Mario is now at PL2";
    }
    else if (currentPower == 2) {
        return "Mario has reached his maximum power level!"; // no increase, he is at max PL
    }
    return "";
}

// method for mario moving to the next level
void Mario::levelUp() {
    gameLevelCount++; // level count of the game increases
}

// method for mario losing power
string Mario::losePower() { 
    if (currentPower == 0) {
        return "Mario is at the minimum power level."; // no decrease, he is at min PL
    }
    else if (currentPower == 1) {
        currentPower = 0; // mario decreases to PL0
        return "Mario is now at PL0";
    }
    else if (currentPower == 2) {
        currentPower = 1; // mario decreases to PL1
        return "Mario is now at PL1";
    }
    return "";
}

// method for when mario encounters a coin
string Mario::encounterCoin() {
    if (coinCount < 20) { // if mario has less than 20 coins
        coinCount = coinCount + 1; // his coin count increases
    }
    else if (coinCount == 20) { // if mario has 20 coins
        lifeCount = lifeCount + 1; // mario gains a life!
        coinCount = 0; // resets coin count
        enemiesDefeated = 0; // if mario gains a life from coins, he can no longer gain a life from defeating 7 enemies so this is reset to 0
    }
    return "";
}

// method for when mario encounters a goomba
string Mario::encounterGoomba() { 
    int random = rand() % 101; // generate random probability for mario's chances of defeat
    string log = ""; // keeps track of mario's activity

    if (random <= 80) { // mario has an 80% chance of defeating a goomba
        enemiesDefeated++;
        log = log + "Mario has defeated the Goomba!";
    }
    else { // mario has a 20% chance of losing to a goomba
        if (currentPower == 0 && lifeCount == 1) {
            lifeCount = lifeCount - 1;
            enemiesDefeated = 0;
            log = log + "Mario lost to the Goomba and had no lives to spare. Game over!";
        }
        else if (currentPower == 0 && lifeCount > 1) { // if mario loses but has lifes he could lose
            lifeCount = lifeCount - 1;
            enemiesDefeated = 0;
            log = log + "Mario lost to the Goomba. He was at PL0, so Mario lost a life.";
        }
        else { // if mario loses and goes down a power level
            losePower();
            log = log + "Mario lost to the Goomba, his power level is now " + to_string(currentPower); 
        }
    }
    if (enemiesDefeated == 7) {
        lifeCount++;
        enemiesDefeated = 0;
        log = log + "Mario has defeated 7 enemies on the same life, so another life has been gained!";
    }
    return log;
}

// method for when mario encounters a koopa
string Mario::encounterKoopa() { 
    int random = rand() % 101; // generate random probability for mario's chances of defeat
    string log = ""; // keep track of mario's activity

    if (random <= 65) { // mario has a 65% chance of defeating a koopa
        enemiesDefeated++;
        log = log + "Mario has defeated the Koopa!";
    }
    else { // mario has a 35% chance of losing to a koopa
        if (currentPower == 0 && lifeCount == 1) {
            lifeCount = lifeCount - 1;
            enemiesDefeated = 0;
            log = log + "Mario lost to the Koopa and had no lives to spare. Game over!";
        }
        else if (currentPower == 0 && lifeCount > 1) { // if mario loses but has lifes he could lose
            lifeCount = lifeCount - 1;
            enemiesDefeated = 0;
            log = log + "Mario lost to the Koopa. He was at PL0, so Mario lost a life.";
        }
        else { // if mario loses and goes down a power level
            losePower();
            log = log + "Mario lost to the Koopa, his power level is now " + to_string(currentPower); 
        }
    }
    if (enemiesDefeated == 7) {
        lifeCount++;
        enemiesDefeated = 0;
        log = log + "Mario has defeated 7 enemies on the same life, so another life has been gained!";
    }
    return log;
}

// method for when mario encounters a boss
string Mario::encounterBoss() {
    int random = rand() % 2; // generates random numbers 50/50 chance
    string log; // keep track of mario's activity

    if (random == 1) { // if Mario wins
        log = log + "Mario defeated the boss! He will advance to the next level!\n";
        enemiesDefeated++;
        levelUp(); // mario levels up
        levelPlay = false; // boolean set to false because mario levels up
    }
    else { // if mario loses
        if (currentPower == 2) {
            losePower(); // mario goes to PL0 and fights again
            losePower();
            log = log + "Mario lost to the boss. He will attempt to defeat him again. Mario's power level is now " + to_string(currentPower);
        }
        else if (currentPower == 1) { // if mario was at PL1
            losePower(); // mario goes to PL0 and fights again
            lifeCount = lifeCount - 1; // mario loses a life
            enemiesDefeated = 0;
            log = log + "Mario lost to the boss and lost a life. He will attempt to defeat him again. Mario is now at PL0 with " + to_string(lifeCount) + " lives left!\n";
        }
        else if (currentPower == 0) { // if mario was at PL0
            lifeCount = lifeCount - 1; // mario loses a life and fights again
            enemiesDefeated = 0;
            log = log + "Mario lost to the boss and lost a life. He will attempt to defeat him again. Mario is now at PL0 with " +to_string(lifeCount) + " lives left!\n";
        }
    }
    if (lifeCount == 0) { // if mario is out of lives
        log = log + "Mario lost to the boss and is out of lives.\n";
    }
    if (enemiesDefeated == 7) {
        lifeCount++;
        enemiesDefeated = 0;
        log = log + "Mario has defeated 7 enemies on the same life, so another life has been gained!";
    }
    return log;
}

// method for when mario encounters a pipe
void Mario::encounterPipe() {
    levelPlay = false; // set to false because mario is no longer in his current level, he has leveled up
}