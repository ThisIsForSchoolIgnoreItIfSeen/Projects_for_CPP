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
  cin.get(inputChar,80,'\n');
  cin.ignore(80,'\n');
  for (int i=0;i<80;i++) {
    if (inputChar[i]==0||inputChar[i]==10)
      break;
    //only takes in ASCII chars so I dont have to take out the punctuation later
    if (('A'<=inputChar[i] && inputChar[i]<='Z')||('a'<=inputChar[i]&&inputChar[i]<='z')) {
      if ('A'<=inputChar[i]&&inputChar[i]<='Z')
	inputChar[i]+=('a'-'A');
      potentialPalindrome[simpleIterator]=inputChar[i];
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
