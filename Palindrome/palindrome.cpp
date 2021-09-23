//Palindrome
//Author: Kabir Vidyarthi
//Date: 9/17/21
# include <iostream>
using namespace std;

int main() {
  //code here
  char potentialPalindrome[80];
  char inputChar[80];
  int simpleIterator = 0;
  //input loop
  while(simpleIterator<80) {
    cin.get(inputChar,10,'\n');
    cin.ignore(80,'\n');
    if (inputChar[0]==0 || inputChar[0]==10) {
      break;
    }
    //only takes in ASCII chars so I dont have to take out the punctuation later
    if (('A'<=inputChar[0] && inputChar[0]<='Z')||('a'<=inputChar[0]&&inputChar[0]<='z')) {
      if ('A'<=inputChar[0]&&inputChar[0]<='Z') {
	inputChar[0]+=('a'-'A');
      }
      potentialPalindrome[simpleIterator]=inputChar[0];
      simpleIterator++;
    }
  }
  //palindrome logic
  int startingPoint=0;
  simpleIterator--;
  bool isIt = true;
  while(startingPoint<simpleIterator) {
    if (potentialPalindrome[startingPoint]!=potentialPalindrome[simpleIterator])
      isIt=false;
    startingPoint++;
    simpleIterator--;
  }
  if (isIt)
    cout << potentialPalindrome << " Is a palindrome";
  else
    cout << potentialPalindrome << " Isn't a palindrome";
  return 0;
}
