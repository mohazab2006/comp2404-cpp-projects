#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 5;
  choice = -1;

  cout << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Print all messages" << endl;
  cout << "  (2) Print all subscribers" << endl;
  cout << "  (3) Print subscribers by activity" << endl;
  cout << "  (4) Compute most frequent sender" << endl;
  cout << "  (5) Compute most frequent receiver" << endl;
  cout << "  (0) Exit" << endl<<endl;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    if (!(cin >> choice)) {
      choice = 0;
      return;
    }
    if (choice == 0)
      return;
  }
}

void View::printStr(string str) { cout << str; }
void View::readInt(int& n) { cin >> n; }
void View::readStr(string& str) { cin >> str; }


