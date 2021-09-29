//Guessing game
//Kabir Vidyarthi
//Date 9/15/21
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  //this is a guessing game
  char playAgain;
  //loop to play multiple times
  do {
    //picks random number within random bound
    srand(time(NULL));
    int bound = rand() % 51 + 50;
    srand(time(NULL));
    int num = rand() % bound;
    std::cout << "A random number has been chosen for you to guess between 0 and " << bound << "\n";
    bool won = false;
    //guesses counter
    int guessesTaken = 0;
    //loop to guess the right number
    while (!won) {
      std::cout <<"You've guessed "<< guessesTaken << " times\n" <<"What's your guess?\n";
      int guess;
      std::cin >> guess;
      if (guess==num) {
	std::cout << "You Won!!\nThe number was " << num << " it took you " << guessesTaken << " tries\n";
	won=true;
	break;
      } else if (guess>num) {
	std::cout << "Too big\n";
      } else {
	std::cout << "Too small\n";
      }
      guessesTaken++;
    }
    //in order to allow multiple plays of the game
    std::cout << "Do you want to play again?\nType 'y' or 'n': ";
    std::cin >> playAgain;
  } while(playAgain=='y');
    return 0;
}
