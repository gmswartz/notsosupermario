/* Author: Grace Swartz (2414391, gswartz@chapman.edu) */
/* PA 2: Mario */
/* Class: CPSC350-02 */
/* Date: 9/24/24 */
/* Summary: reads input and outputs the outcome of the program once ran */

#include "Level.h"
#include "World.h"
#include "Mario.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {
    srand(time(0)); // for random

    //default values of game probabilites
    int levelCount = 3;
    int gridDimensions = 5;
    int lifeCount = 3;
    int randCoin = 20;
    int randMushroom = 20;
    int randGoomba = 20;
    int randKoopa = 20;
    int randNothing = 20;

    if (argc == 3) {
        ifstream file(argv[1]); // open file

        if (file.is_open()) {
            string readLine; // keeps track of line by line
            for (int i=0; i<8; ++i) { // iterating through each line of the input file
                getline(file, readLine);
                if (i==0) {
                    levelCount = stoi(readLine);
                }
                else if (i == 1) {
                    gridDimensions = stoi(readLine);
                }
                else if (i == 2) {
                    lifeCount = stoi(readLine);
                }
                else if (i == 3) {
                    randCoin = stoi(readLine);
                }
                else if (i == 4) {
                    randMushroom = stoi(readLine);
                }
                else if (i == 5) {
                   randGoomba = stoi(readLine);
                }
                else if (i == 6) {
                    randKoopa = stoi(readLine);
                }
                else if (i == 7) {
                    randNothing = stoi(readLine);
                }
            }
            file.close();
        }
        //"""BEGIN CODE FROM CHAT GPT, PROMPT ASKED: error handling input file opening c++"""
        else {
            cerr << "Error opening file: " << argv[1] << endl;
            return 1; // return an error code
        }
        //"""END OF CODE FROM CHAT GPT"""
    }

    // putting it all together for it to go onto output file
    World gameWorld = World(levelCount, gridDimensions, randCoin, randNothing, randMushroom, randGoomba, randKoopa);
    string gameOutput = gameWorld.playMario(lifeCount);

    ofstream outputFile(argv[2]);
    if (outputFile.is_open()) { 
        outputFile << gameOutput; // everything that happens is added to the file
        outputFile.close(); // closing file
    }
    //"""BEGIN CODE FROM CHAT GPT, PROMPT ASKED: error handling output file opening c++"""
        else {
            cerr << "Error opening file: " << endl;
            return 1; // return an error code
        }
        //"""END OF CODE FROM CHAT GPT""""
    return 0;
}