#include "mathGame.hpp"

// Implementation

MathGame::MathGame() { 
  runGame();
}

void MathGame::runGame() {
  gameMode();
}

/* Choose Game Mode */
void MathGame::gameMode() {
  int choice;
  int max;

  do {
    std::cout << "Please choose a game mode:" << "\n \n"
              << "1 - Addition" << "\n"
              << "2 - Subtraction" << "\n"
              << "3 - Multiplication" << std::endl;

    std::cout << "Enter Game Mode Number: ";
    std::cin >> choice;

    if ((choice != 1) && (choice != 2) && (choice != 3)) {
      std::cout << "Invalid input. Please choose an number between 1 - 3. \n" << std::endl;
    }

  } while ((choice != 1) && (choice != 2) && (choice != 3));
  
  std::cout << std::endl << "Enter max integer you would like to see: ";
  std::cin >> max;
  std::cout << std::endl << "The number range is now 0 - " << max << "." << std::endl;


  switch(choice) {
    case 1:
      runAddition(max);
      break;
    case 2:
      runSubtraction(max);
      break;
    case 3:
      runMultiplication(max);
      break;
  }
  
}

void MathGame::setGameOver() {
  this->gameOver = !this->gameOver;
}

/* End Game */
void MathGame::endGame() {
  this->gameOver = false;
  std::string choice;

  do {
    std::cout << "Game Over. Try Again? (yes / no): ";
    std::cin >> choice;

    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    if ((choice != "YES") && (choice != "NO")) {
      std::cout << "Incorrect input. Please select either yes or no." << std::endl;
    }    

  } while ((choice != "YES") && (choice != "NO"));

  if (choice == "YES") {
    // Try Again
    setGameOver();
    runGame();
  } else {
    // Game Over
    std::cout << "Game Over." << std::endl;

    exit(0);

  }
}

/* Game Modes */
void MathGame::runAddition(int max) {
  printf("Running addition \n");

  int num1, num2;
  int count = 0;
  srand(time(NULL));

  setStartTime();

  while ((!this->gameOver) && (count < 11)) {
    int a = rand() % max;
    int b = rand() % max;
    int ans;

    std::cout << a << " + " << b << " = "; 
    std::cin >> ans;

    if (ans != (a + b)) {
      std::cout << "Wrong answer! The correct answer is " << (a + b) << std::endl;
      endGame();
    }

    count++;
  }

  setFinishTime();

  std::chrono::duration<double> elapsed = calcElapsedTime();

  std::cout << "Elapsed time: " << elapsed.count() << " s \n";

}

void MathGame::runSubtraction(int max) {
  printf("Running subtraction \n");
  int num1, num2;
  int count = 0;
  srand(time(NULL));

  setStartTime();

  while ((!this->gameOver) && (count < 11)) {
    int a = rand() % max;
    int b = rand() % max;
    int ans;

    std::cout << a << " - " << b << " = "; 
    std::cin >> ans;

    if (ans != (a - b)) {
      std::cout << "Wrong answer! The correct answer is " << (a - b) << std::endl;
      endGame();
    }

    count++;
  }

  setFinishTime();

  std::chrono::duration<double> elapsed = calcElapsedTime();

  std::cout << "Elapsed time: " << elapsed.count() << " s \n";
}

void MathGame::runMultiplication(int max) {
  printf("Running multiplication \n");

  int num1, num2;
  int count = 0;
  srand(time(NULL));

  setStartTime();

  while ((!this->gameOver) && (count < 11)) {
    int a = rand() % max;
    int b = rand() % max;
    int ans;

    std::cout << a << " * " << b << " = "; 
    std::cin >> ans;

    if (ans != (a * b)) {
      std::cout << "Wrong answer! The correct answer is " << (a * b) << std::endl;
      endGame();
    }

    count++;
  }

  setFinishTime();

  std::chrono::duration<double> elapsed = calcElapsedTime();

  std::cout << "Elapsed time: " << elapsed.count() << " s \n";
}

/* Timer Functions */
void MathGame::setStartTime() {
  this->start = std::chrono::high_resolution_clock::now();
}

void MathGame::setFinishTime() {
  this->finish = std::chrono::high_resolution_clock::now();
}

std::chrono::duration<double> MathGame::calcElapsedTime() {
  return this->finish - this->start;
}

