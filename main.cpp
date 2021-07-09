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
  int hn;
  int ln;
  cout << "The highest number in the range?" << endl;
  cin >> hn;
  cout << "The lowest number in the range?" << endl;
  cin >> ln;

  bool found = false;
  int start = ln;
  int end = hn;
  while (!found) {
    int mid = (start+end)/2;
    int ok = sGuess(mid);
    if (ok == 0) {
      int cdt = ask();
      if (cdt == 0) {
        end = mid - 1;
      } else if(cdt == 1) {
        start = mid + 1;
      }
    } else if (ok == 1) {
      cout << "Yay!" << endl;
      found = true;
    }
  }
}