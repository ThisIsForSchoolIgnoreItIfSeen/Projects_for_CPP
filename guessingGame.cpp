#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  //this is a guessing game
  std::string playAgain;
  //generate random number
  do {
    srand(time(NULL));
    int bound = rand() % 51 + 50;
    srand(time(NULL));
    int num = rand() % bound;
    std::cout << "A random number has been chosen for you to guess between 0 and " << bound << "\n";
    bool won = false;
    //loop to guess the right number
    for (int i = 0;i<10;i++) {
      std::cout <<"What's your guess?\n";
      int guess;
      std::cin >> guess;
      if (guess==num) {
	std::cout << "You Won!!\nThe number was " << num << "\n";
	won=true;
	break;
      } else if (guess>num) {
	std::cout << "Too big\n";
      } else {
	std::cout << "Too small\n";
      }
    }
    if (!won)
      std::cout << "Too bad, you ran out of lives, the number was " << num << "\n";
    //in order to allow multiple plays of the game
    std::cout << "Do you want to play again?\nType 'y' or 'n': ";
    std::cin >> playAgain;
  } while(playAgain=="y");
    return 0;
}
