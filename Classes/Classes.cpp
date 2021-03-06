//Kabir Vidyarthi
//Classes work
//10/5/21
#include <iostream>
#include <vector>
#include "media.h"
#include "videoGame.h"
#include "song.h"
#include "movie.h"
using namespace std;

videoGame* getGame(videoGame* tempvalue) {
  //function to quickly recieve a videogame from the user
  cout << "Whats the name of the video game?\n";
  cin.get(tempvalue->name,80,'\n');
  cin.ignore(80,'\n');
  cout << "When was it released?\n";
  cin >> tempvalue->year;
  cin.ignore(80,'\n');
  cout << "Who published it?\n";
  cin.get(tempvalue->publisher,80,'\n');
  cin.ignore(80,'\n');
  cout << "what was its rating?\n";
  cin >> tempvalue->rating;
  cin.ignore(80,'\n');
  return tempvalue;
}

song* getSong(song* tempvalue) {
  //a function to quickly get a song from the user(I made it into a function so that I could test it before making the code loop)
  cout << "What's the name of the song?\n";
  cin.get(tempvalue->name,80,'\n');
  cin.ignore(80,'\n');
  cout << "Who made the song?\n";
  cin.get(tempvalue->artist,80,'\n');
  cin.ignore(80,'\n');
  cout << "Who published the song?\n";
  cin.get(tempvalue->publisher,80,'\n');
  cin.ignore(80,'\n');
  cout << "When was the song published?\n";
  cin >> tempvalue->year;
  cout << "How long is the song?\n";
  cin >> tempvalue->length;
  cin.ignore(80,'\n');
  return tempvalue;
};

movie* getMovie(movie* temp) {
  //function to get a movie from the user
  cout << "Name of movie?\n";
  cin.get(temp->name,80,'\n');
  cin.ignore(80,'\n');
  cout << "Director?\n";
  cin.get(temp->publisher,80,'\n');
  cin.ignore(80,'\n');
  cout << "When was it made?\n";
  cin >> temp->year;
  cout << "How long is it?\n";
  cin >> temp->duration;
  cout << "What was it rated?\n";
  cin >> temp->rating;
  cin.ignore(80,'\n');
  return temp;
}

bool charComparer(char *f, char *s) {
  //something to compare the char arrays, bc we can't use strings
  while (*f&&*s) {
    if (*f!=*s) {
      return false;
    }
    f++;
    s++;
  }
  return true;
}

int main() {
  vector<media*> sayingMediasSoundsHellish;
  //loop control vals
  char command[10] = "print";
  char type[10];
  bool quit = false;
  char commands[4][10] = {"add","print","search","delete"};
  char mediaTypes[3][10] = {"game","song","movie"};
  //loop
  while(!quit) {
    //get a new command
    cout << "Would you like to 'ADD', 'PRINT', 'SEARCH', or 'DELETE'?\n";
    cin.get(command,10,'\n');
    cin.ignore(80,'\n');
    //puts command in lowercase to prevent errors
    for (int i=0;i<10;i++) {
      if (command[i]==0||command[i]==10)
	break;
      command[i] = tolower(command[i]);
    }
    if (charComparer(command,commands[0])) {
      //add
      char addType[10];
      cout << "Would you like to add a 'GAME', 'SONG', 'MOVIE', or go 'BACK'?\n";
      cin.get(addType,10,'\n');
      cin.ignore(80,'\n');
      //puts media type in lowercase to prevent errors
      for (int i=0;i<10;i++) {
	if (addType[i]==0||addType[i]==10)
	  break;
        addType[i] = tolower(addType[i]);
      }
      if (charComparer(addType,mediaTypes[0])) {
	//game
	sayingMediasSoundsHellish.push_back(getGame(new videoGame()));
      }
      else if (charComparer(addType,mediaTypes[1])) {
	//song
	sayingMediasSoundsHellish.push_back(getSong(new song()));
      }
      else if (charComparer(addType,mediaTypes[2])) {
	//movie
        sayingMediasSoundsHellish.push_back(getMovie(new movie()));
      }
    } else if (charComparer(command,commands[1])) {
      //print
      for (auto i=sayingMediasSoundsHellish.begin();i!=sayingMediasSoundsHellish.end();++i) {
	(*i)->disp();
      }
    } else if (charComparer(command,commands[2])) {
      //search
      //get the name/year
      char id[80];
      cout << "What is the name or year of publication of the media that you wish to access?\n";
      cin.get(id,80,'\n');
      cin.ignore(80,'\n');
      for (int i=0;i<sayingMediasSoundsHellish.size();i++) {
	//iterates through list
	if (charComparer(sayingMediasSoundsHellish[i]->name,id)||to_string(sayingMediasSoundsHellish[i]->year)==id) {
	  //checks if it has the same name or year
	  sayingMediasSoundsHellish[i]->disp();
	}
      }
    } else if (charComparer(command,commands[3])) {
      //delete
      char id[80];
      char confirmation[5];
      cout << "What's the name of the media you wish to delete or it's year of publication?\n";
      cin.get(id,80,'\n');
      cin.ignore(80,'\n');
      for (auto i=sayingMediasSoundsHellish.begin();i!=sayingMediasSoundsHellish.end();++i) {
	//finds the right medias to delete
	if (charComparer((*i)->name,id)||to_string((*i)->year)==id) {
	  //prints it out for confirmation
	  (*i)->disp();
	  cout <<"Are you sure you wish to delete this?\n'y' or 'n':";
	  cin.get(confirmation,5,'\n');
	  cin.ignore(80,'\n');
	  if (confirmation[0]=='y') {
	    //deletes
	    sayingMediasSoundsHellish.erase(i--);
	  }
	}
      }
    } else {
      quit = true;
    }
  }
  return(0);
}
