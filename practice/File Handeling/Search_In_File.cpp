#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string state, str, Capital, State, capital, garbage, choice = "yes";
  char ch, s;

  while (1)
  {
    if (choice == "yes")
    {
      cout << endl;
      ifstream myfile("state_capital.txt", ios ::in);
      cout << "\tPress c for find capital.";
      cout << "\n\tPress s for find state.";
      cout << "\n\tEnter your choice : ";
      cin >> ch;
      getline(cin, garbage);
      if (myfile.is_open())
      {
        if (ch == 'c')
        {
          cout << "\nEnter the name of state : ";
          getline(cin, State);
          while (getline(myfile, str))
          {
            int length = str.length();
            int dash_at = str.find("-");
            state = str.substr(0, dash_at - 1);
            capital = str.substr((dash_at + 2), length);
            if (state == State)
              cout << "Capital : " << capital;
          }
        }
        else if (ch == 's')
        {
          cout << "\nEnter the name of capital : ";
          getline(cin, Capital);
          while (getline(myfile, str))
          {
            int length = str.length();
            int dash_at = str.find("-");
            state = str.substr(0, dash_at - 1);
            capital = str.substr((dash_at + 2), length);
            if (capital == Capital)
              cout << "State : " << state;
          }
        }
        else
          cout << "\n\t~worong input~";
        myfile.close();
      }
      else
      {
        cout << "not found";
      }
      cout << endl;
      cout << endl;
      cout << endl;
    }
    cout << "\n\nType yes for continue";
    cout << "\nType no for exit\n\t";
    cout << "Continue : ";
    cin >> choice;
    if (choice == "no")
      break;
    else if (choice != "yes")
      cout << "\n\t~worong input~\n\tType Again";
  }
}