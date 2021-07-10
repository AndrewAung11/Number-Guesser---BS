#include <iostream>

using namespace std;

int sGuess(int guess) {
  char input;
  cout << "Is the number " << guess << "? y/n" << endl;
  cin >> input;
  if (input == 'y') {
    return 1;
  } else if (input == 'n') {
    return 0;
  }
  return -1;
}

int ask() {
  int input;
  cout << "Is number:\n\t1. Low\n\t2. High" << endl;
  cin >> input;
  if (input == 1) {
    return 0;
  } else if (input == 2) {
    return 1;
  }
  return -1;
}

int main() {
  //highest number in the range
  int hn;
  //lowest number int the range
  int ln;

  cout << "The highest number in the range?" << endl;
  cin >> hn;

  cout << "The lowest number in the range?" << endl;
  cin >> ln;

  bool found = false;
  //start of the search range
  int start = ln;
  //end of the search range
  int end = hn;
  
  //if haven't found
  while (!found) {
    //mid number of the range | guess
    int mid = (start+end)/2;
    //ask if it is
    int ok = sGuess(mid);
    //if not
    if (ok == 0) {
      //ask the condition of the guess
      int cdt = ask();
      //if guess is high
      if (cdt == 1) {
        end = mid - 1;
      } else if (cdt == 0) { //if low
        start = mid + 1;
      }
    } else if (ok == 1) {
      cout << "Yay!" << endl;
      found = true;
    }
  }
}