/* Author: Author: Grace Swartz (2414391, gswartz@chapman.edu) */
/* PA 2: Mario */
/* Class: CPSC350-02 */
/* Date: 9/24/24 */
/* Summary: implements makeLevel class where the grid is created and populated with items 
    - write methods to place mario, place pipe, and place boss, print level, and return dimensions
    - writes method to move mario around based on random probability of movement */

#include "Level.h"
using namespace std;

makeLevel::makeLevel() { // constructor
    gridDimensions = 10; // dimensions automatically are set

    // creating array
    grid = new char*[10];
    for (int i=0; i < 10; ++i) { // populating the grid with x's (aka nothing)
        grid[i] = new char[10];
        for (int j=0; j < 10; ++j) {
            grid[i][j] = 'x';
        }
    }
    int i = 0;
    char currIndex; // current spot

    // generating the 20% probability of coins and placing them by randomizing a spot
    while (i < 20) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'c'; // if random index lands on 'x', the spot becomes a c (aka a coin)
            i++;
        }
    }
    i=0;
    // generating the 20% probability of mushrooms and placing them by randomizing a spot
    while (i < 20) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'm'; // if random index lands on 'x', the spot becomes an m (aka a mushroom)
            i++;
        }
    }
    i=0;
    // generating the 20% probability of goombas and placing them by randomizing a spot
    while (i < 20) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'g'; // if random index lands on 'x', the spot becomes a g (aka a goomba)
            i++;
        }
    }
    i=0;
    // generating the 20% probability of koopas and placing them by randomizing a spot
    while (i < 20) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'k'; // if random index lands on 'x', the spot becomes a k (aka a koopa)
            i++;
        }
    }
        //place boss
    while(true) {
        int randomRow = rand() % gridDimensions;
        int randomCol = rand() % gridDimensions;

        if (grid[randomRow][randomCol] != 'w' && grid[randomRow][randomCol] != 'H' && grid[randomRow][randomCol] != 'b') {
            grid[randomRow][randomCol] = 'b'; // as long as the space doesn't have a pipe, mario, or boss, a boss is placed
            break;
        }
        else {
            continue;
        }
    }

    //place pipe
        while(true) {
        int randomRow = rand() % gridDimensions;
        int randomCol = rand() % gridDimensions;

        if (grid[randomRow][randomCol] != 'w' && grid[randomRow][randomCol] != 'H' && grid[randomRow][randomCol] != 'b') {
            grid[randomRow][randomCol] = 'w'; // as long as the space doesn't have a pipe, mario, or boss, a pipe is placed
            break;
        }
        else {
            continue;
        }
    }
}

makeLevel::makeLevel(int gridDimensions, int randCoin, int randNothing, 
    int randMushroom, int randGoomba, int randKoopa) { // overloaded constructor with parameters for probability of level options

    this->gridDimensions = gridDimensions; // assigning parameter gridDimensions to member variable
    grid = new char *[gridDimensions]; // creating array similarly to lines 13-17, but populating it based on given parameters
    for (int i=0; i < gridDimensions; ++i) { // indexing through  rows and cols to place x's in each spot
        grid[i] = new char[gridDimensions];
        for (int j=0; j < gridDimensions; ++j) {
            grid[i][j] = 'x';
        }
    }
    int i = 0;
    char currIndex;

    //each while loop is for populating the grid with probabilities (provided at runtime)
    while (i < (double(randCoin / 100.0) * (gridDimensions * gridDimensions))) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'c'; // if random index lands on 'x', the spot becomes a c (aka a coin)
            i++;
        }
    }
    i = 0;
    while (i < (double(randGoomba / 100.0) * (gridDimensions * gridDimensions))) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'g'; // if random index lands on 'x', the spot becomes a g (aka a goomba)
            i++;
        }
    }
    i = 0;
    while (i < (double(randKoopa / 100.0) * (gridDimensions * gridDimensions))) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'k'; // if random index lands on 'x', the spot becomes a k (aka a koopa)
            i++;
        }
    }
    i = 0;
    while (i < (double(randMushroom / 100.0) * (gridDimensions * gridDimensions))) {
        int row = rand() % gridDimensions;
        int col = rand() % gridDimensions;
        currIndex = grid[row][col];
        if (currIndex == 'x') { 
            grid[row][col] = 'm'; // if random index lands on 'x', the spot becomes a m (aka a mushroom)
            i++;
        }
    }
} 

makeLevel::~makeLevel(){}
// destructor

// method to place mario
void makeLevel::placeMario(int gridDimensions) { 
    while(true) {
        int randomRow = rand() % gridDimensions;
        int randomCol = rand() % gridDimensions;

        if (grid[randomRow][randomCol] != 'w' && grid[randomRow][randomCol] != 'H' && grid[randomRow][randomCol] != 'b') {
            grid[randomRow][randomCol] = 'H';
            break;
        }
        else {
            continue;
        }
    }
}

// method to return grid dimensions of level
int makeLevel::getLevelDimensions() {
    return gridDimensions;
}

// method to place warp pipe
void makeLevel::placeWarpPipe() {
    while(true) {
        int randomRow = rand() % gridDimensions;
        int randomCol = rand() % gridDimensions;

        if (grid[randomRow][randomCol] != 'w' && grid[randomRow][randomCol] != 'H' && grid[randomRow][randomCol] != 'b') {
            grid[randomRow][randomCol] = 'w'; // as long as the space doesn't have a pipe, mario, or boss, a pipe is placed
            break;
        }
        else {
            continue;
        }
    }
}

//method to place boss
void makeLevel::placeBoss() {
    while(true) {
        int randomRow = rand() % gridDimensions;
        int randomCol = rand() % gridDimensions;

        if (grid[randomRow][randomCol] != 'w' && grid[randomRow][randomCol] != 'H' && grid[randomRow][randomCol] != 'b') {
            grid[randomRow][randomCol] = 'b'; // as long as the space doesn't have a pipe, mario, or boss, a boss is placed
            break;
        }
        else {
            continue;
        }
    }
}

// method to print out level
string makeLevel::displayLevel() { 
    string printedGrid; // keeping track of ptrinted grid

    // for loop to iterate through grid and add elements
    for (int i=0; i < gridDimensions; ++i) {
        for (int j=0; j < gridDimensions; ++j) {
            printedGrid = printedGrid + grid[i][j];
        }
        printedGrid = printedGrid + "\n";
    }
    return printedGrid;
}

// method to move mario
string makeLevel::moveMario(Mario* marioObj) {
    string movementLog = ""; // to keep track of mario's movement

    // ints for current location
    int currentY;
    int currentX;
    // ints for where mario will be next
    int nextY;
    int nextX;

    //for loop to find mario and keep track of where he currently is
    for (int j=0; j < gridDimensions; ++j) {
        for (int i=0; i < gridDimensions; ++i) {
            if (grid[j][i] == 'H') {
                currentY = j;
                currentX = i;
                break;
            }
        }
    }

    movementLog += + "\nMario is at position (" + to_string(currentY + 1) + "," + to_string(currentX + 1) + "). Mario is at power level " + to_string(marioObj->currentPower) + ".\n";

    int move = rand() % 4; // 25% chance to move either up, down, left, or right

    if (move==0) { //move up
        if (currentY != 0) {
            nextX = currentX;
            nextY = currentY - 1;
        }
        else if (currentY == 0) {
            nextX = currentX; 
            nextY = gridDimensions - 1; // mario will wrap around the grid and move down to index 0
        }
        if (grid[nextY][nextX] == 'c') {
            movementLog += "Mario will move UP. He collected a coin! " + marioObj->encounterCoin() + "\n";
        }
        else if (grid[nextY][nextX] == 'g') {
            movementLog += "Mario will move UP. He encountered a goomba! " + marioObj->encounterGoomba() + "\n";
        }
        else if (grid[nextY][nextX] == 'k') {
            movementLog += "Mario will move UP. He encountered a koopa! " + marioObj->encounterKoopa() + "\n";
        }
        else if (grid[nextY][nextX] == 'm') {
            movementLog += "Mario will move UP. He ate a mushroom! " + marioObj->gainPower() + "\n";
        }
        else if (grid[nextY][nextX] == 'x') {
            movementLog += "Mario will move UP. He found nothing.\n";
        }
        else if (grid[nextY][nextX] == 'w') {
            movementLog += "Mario will move UP. He encountered a warp pipe! Mario will move to the next level!\n";
            marioObj->encounterPipe();
        }
        else if (grid[nextY][nextX] == 'b') {
            movementLog += "Mario will move UP. He encountered the level boss!\n";
            marioObj->encounterBoss();
        }
        grid[nextY][nextX] = 'H'; // placing mario
        grid[currentY][currentX] = 'x'; //replacing mario's previous spot with x
        currentX = nextX;
        currentY = nextY;
    }

    else if (move==1) { //move down
        if (currentY != gridDimensions - 1) {
            nextX = currentX;
            nextY = currentY + 1;
        }
        else if (currentY == gridDimensions - 1) {
            nextX = currentX; 
            nextY = 0; // mario will wrap around the grid and move down to index 0
        }
        if (grid[nextY][nextX] == 'c') {
            movementLog += "Mario will move DOWN. He collected a coin! " + marioObj->encounterCoin() + "\n";
        }
        else if (grid[nextY][nextX] == 'g') {
            movementLog += "Mario will move DOWN. He encountered a goomba! " + marioObj->encounterGoomba() + "\n";
        }
        else if (grid[nextY][nextX] == 'k') {
            movementLog += "Mario will move DOWN. He encountered a koopa! " + marioObj->encounterKoopa() + "\n";
        }
        else if (grid[nextY][nextX] == 'm') {
            movementLog += "Mario will move DOWN. He ate a mushroom! " + marioObj->gainPower() + "\n";
        }
        else if (grid[nextY][nextX] == 'x') {
            movementLog += "Mario will move DOWN. He found nothing.\n";
        }
        else if (grid[nextY][nextX] == 'w') {
            movementLog += "Mario will move DOWN. He encountered a warp pipe! Mario will move to the next level!\n";
            marioObj->encounterPipe();
        }
        else if (grid[nextY][nextX] == 'b') {
            movementLog += "Mario will move UP. He encountered the level boss!\n";
            marioObj->encounterBoss();
        }
        grid[nextY][nextX] = 'H'; // placing mario
        grid[currentY][currentX] = 'x'; //replacing mario's previous spot with x
        currentX = nextX;
        currentY = nextY;
    }

    else if (move==2) { //move right
        if (currentX != gridDimensions - 1) {
            nextX = currentX + 1;
            nextY = currentY;
        }
        else if (currentX == gridDimensions - 1) {
            nextX = 0; // mario will wrap around the grid and move right to index 0
            nextY = currentY;
        }
        if (grid[nextY][nextX] == 'c') {
            movementLog += "Mario will move RIGHT. He collected a coin! " + marioObj->encounterCoin() + "\n";
        }
        else if (grid[nextY][nextX] == 'g') {
            movementLog += "Mario will move RIGHT. He encountered a goomba! " + marioObj->encounterGoomba() + "\n";
        }
        else if (grid[nextY][nextX] == 'k') {
            movementLog += "Mario will move RIGHT. He encountered a koopa! " + marioObj->encounterKoopa() + "\n";
        }
        else if (grid[nextY][nextX] == 'm') {
            movementLog += "Mario will move RIGHT. He ate a mushroom! " + marioObj->gainPower() + "\n";
        }
        else if (grid[nextY][nextX] == 'x') {
            movementLog += "Mario will move RIGHT. He found nothing.\n";
        }
        else if (grid[nextY][nextX] == 'w') {
            movementLog += "Mario will move RIGHT. He encountered a warp pipe! Mario will move to the next level!\n";
            marioObj->encounterPipe();
        }
        else if (grid[nextY][nextX] == 'b') {
            movementLog += "Mario will move UP. He encountered the level boss!\n";
            marioObj->encounterBoss();
        }
        grid[nextY][nextX] = 'H'; // placing mario
        grid[currentY][currentX] = 'x'; //replacing mario's previous spot with x
        currentX = nextX;
        currentY = nextY;
    }
    else if (move==3) { //move left
        if (currentX != 0) {
            nextX = currentX - 1;
            nextY = currentY;
        }
        else if (currentY == 0) {
            nextX = gridDimensions - 1; 
            nextY = currentY; // mario will wrap around the grid and move down to index 0
        }
        if (grid[nextY][nextX] == 'c') {
            movementLog += "Mario will move LEFT. He collected a coin! " + marioObj->encounterCoin() + "\n";
        }
        else if (grid[nextY][nextX] == 'g') {
            movementLog += "Mario will move LEFT. He encountered a goomba! " + marioObj->encounterGoomba() + "\n";
        }
        else if (grid[nextY][nextX] == 'k') {
            movementLog += "Mario will move LEFT. He encountered a koopa! " + marioObj->encounterKoopa() + "\n";
        }
        else if (grid[nextY][nextX] == 'm') {
            movementLog += "Mario will move LEFT. He ate a mushroom! " + marioObj->gainPower() + "\n";
        }
        else if (grid[nextY][nextX] == 'x') {
            movementLog += "Mario will move LEFT. He found nothing.\n";
        }
        else if (grid[nextY][nextX] == 'w') {
            movementLog += "Mario will move LEFT. He encountered a warp pipe! Mario will move to the next level!\n";
            marioObj->encounterPipe();
        }
        else if (grid[nextY][nextX] == 'b') {
            movementLog += "Mario will move UP. He encountered the level boss!\n";
            marioObj->encounterBoss();
        }
        grid[nextY][nextX] = 'H'; // placing mario
        grid[currentY][currentX] = 'x'; //replacing mario's previous spot with x
        currentX = nextX;
        currentY = nextY;
    }

    movementLog += "Mario has " + to_string(marioObj->lifeCount) + " lives. He has " + to_string(marioObj->coinCount) + " coin(s).\n\n";
    return movementLog; //return mario's log
}