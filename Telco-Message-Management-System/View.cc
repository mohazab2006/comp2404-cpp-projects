#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 3;

  cout << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Compute most frequent sender" << endl;
  cout << "  (2) Compute most frequent receiver" << endl;
  cout << "  (3) Print subscribers" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printStr(string str) { cout << str; }
void View::readInt(int& n) { cin >> n; }
void View::readStr(string& str) { cin >> str; }


