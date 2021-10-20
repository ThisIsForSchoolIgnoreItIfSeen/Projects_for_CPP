//Tic-Tac-Toe
//Author: Kabir Vidyarthi
//Date: 9/27/21
#include <iostream>
using namespace std;

int main() {
  char gameBoard[4][4] = {{' ','1','2','3'},{'1',' ',' ',' '},{'2',' ',' ',' '},{'3',' ',' ',' '}};
  int valueBoard[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
  bool won = false;
  int winner = 0;
  int row=2;
  int column=2;
  bool playerOneTurn = true;
  //gameloop
  while (!won) {
    //board display loop
    for (int i=0;i<4;i++) {
      for (int j=0;j<4;j++)
	cout << gameBoard[i][j] << '|';
      cout << "\n--------\n";
    }
    if (playerOneTurn) {
      //announcing player 1's turn
      cout << "It's player 1's turn\n";
    }
    else {
      //announcing player 2's turn
      cout << "It's player 2's turn\n";
    }
    //collects where to put tile
    cout << "Which row would you like to put your tile in\n";
    cin >> row;
    cout << "Which column would you like to place your tile in\n";
    cin >> column;
    //gives tile to the correct player if the tile isn't already taken
    if (valueBoard[row-1][column-1]!=0) {
      cout << "that tile's taken already\n";
      continue;
    }
    if (playerOneTurn) {
      valueBoard[row-1][column-1]=1;
      gameBoard[row][column]='X';
      playerOneTurn=false;
    } else {
      valueBoard[row-1][column-1]=2;
      gameBoard[row][column]='O';
      playerOneTurn=true;
    }
    //win logic if mess statements
    //Checking for a draw
    won=true;
    for (int i=0;i<3;i++)
      for (int j=0;j<3;j++)
	if (valueBoard[i][j]==0)
	  won=false;
    //diagonal win conditions
    if ((valueBoard[0][0]==valueBoard[1][1]&&valueBoard[1][1]==valueBoard[2][2])||(valueBoard[0][2]==valueBoard[1][1]&&valueBoard[1][1]==valueBoard[2][0])&&valueBoard[1][1]!=0) {
      if (valueBoard[1][1]!=0) {
	won=true;
	winner = valueBoard[1][1];
      }
    }
    //Horizontal and vertical win conditions
    for (int i=0;i<3;i++) {
      if (((valueBoard[i][0]==valueBoard[i][1]&&valueBoard[i][1]==valueBoard[i][2])||(valueBoard[0][i]==valueBoard[1][i]&&valueBoard[1][i]==valueBoard[2][i]))&&valueBoard[i][i]!=0) {
	won = true;
	winner = valueBoard[i][i];
      }
    }
  }
  
    //board display loop
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++)
      cout << gameBoard[i][j] << '|';
    cout << "\n--------\n";
  }
  //stating the winner
  if (winner==0)
    cout << "nobody won";
  else
    cout << "Player " << winner << " won!\n";
  //Play again stuff
  cin.ignore(80,'\n');
  char answer[5];
  cout << "Would you like to play again?\n'y' or 'n':";
  cin.get(answer,3,'\n');
  cin.ignore(80,'\n');
  if ((answer[0]=='N')||(answer[0]=='n'))
    return 0;
  return main();
}
