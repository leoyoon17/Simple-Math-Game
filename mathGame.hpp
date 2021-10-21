// MathGame Interface

#ifndef MATHGAME_H_
#define MATHGAME_H_

#include <iostream>
#include <cstdio>
#include <chrono>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <algorithm>

class MathGame {
  private:
    bool gameOver = false;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> finish;

    enum gameModes { addition, subtraction, multiplication, division };

  public:
    MathGame();
    void runGame();

    void setGameOver();

    // Timer Functions
    void setStartTime();
    void setFinishTime();
    std::chrono::duration<double> calcElapsedTime();

    // Choose Game Mode
    void gameMode();

    // End Game
    void endGame();

    // Addition Game
    void runAddition(int max);

    // Subtraction Game
    void runSubtraction(int max);

    // Multiplication Game
    void runMultiplication(int max);
    
    

    // Division Game?




};


#endif //MATHGAME_H_