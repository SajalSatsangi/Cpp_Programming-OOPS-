#include <iostream>
using namespace std;

class bank_account
{
  int accountNumber;
  string account_holder_name;
  int amount = 10000;

public:
  bank_account(int accountNumber, string account_holder_name)
  {
    this->accountNumber = accountNumber;
    this->account_holder_name = account_holder_name;
    cout << "Bank Balance : " << amount << endl;
  }

  int holder_interest(int principal, int rate, int time)
  {
    int s;
    s = principal * rate * time / 100;
    return s;
  }

  void display()
  {
    cout << "account nummber : " << accountNumber << endl;
    cout << "account holder name : " << account_holder_name << endl;
  }

  void withdrawl()
  {
    int money;
    cout << "enter the amount:";
    cin >> money;
    amount = amount - money;
    cout << "withdrawl amount" << money << endl;
    cout << "Bank Balance : " << amount << endl;
  }

  void deposit()
  {
    int money;
    cout << "enter the amount:";
    cin >> money;
    amount = amount + money;
    cout << "deposited money" << money << endl;
    cout << "Bank Balance : " << amount << endl;
  }
};

int main()
{
  int SI_1, SI_2;
  bank_account person1(2104090, "kanishka pathik");
  bank_account person2(2104410, "sajal satsangi");

  person1.display();
  person2.display();

  SI_1 = person1.holder_interest(5000, 12, 2);
  SI_2 = person2.holder_interest(4000, 25, 4);

  cout << " interest for kanishka pathik: " << SI_1 << endl;
  cout << "interest for sajal satsangi: " << SI_2 << endl;

  person1.withdrawl();
  person2.withdrawl();

  person1.deposit();
  person2.deposit();

  return 0;
}