#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream myfile("state_capital.txt", ios::out);
    string capital;
    string state;
    int n;
    string garbage;
    if (myfile.is_open())
    {   
        cout << "Enter the no of states :";
        cin >> n;
        getline(cin, garbage);
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter the state : ";
            getline(cin, state);
            myfile << state;
            myfile << " - ";
            cout << "Enter the capital : ";
            getline(cin, capital);
            myfile << capital;
            myfile << "\n";
        }
        myfile.close();
    }
    else
    {
        cout << "not found";
    }
}