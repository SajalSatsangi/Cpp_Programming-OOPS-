#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Create the necessary instance variables. These instance variables should only be accessible inside the Account class.
class Account
{
  string accountName;    // An account name(account holder name).
  long accountNumber;    // An account number, which will be a whole number.
  double accountBalance; // An account balance representing a quantity of cash.

public:
  Account()
  {
    // Leave Blank
  }
  // Constructor--> Sets the instance variables of the class and Limitations of instance variables must be imposed
  Account(string accountName, long accountNumber, double accountBalance)
  {
    if (checkAccountName(accountName)) // cheack validity of account name by the function which is define below
      this->accountName = accountName;
    else
    {
      this->accountName = "Not Valid";
      cout << "Account Holder Name is not validate" << endl;
    }
    if (checkAccountNo(accountNumber)) // cheack validity of account no by the function which is define below
      this->accountNumber = accountNumber;
    else
    {
      this->accountNumber = 0;
      cout << "Account Number is not validate" << endl;
    }
    if (checkAccountBalance(accountBalance)) // cheack validity of account balance by the function which is define below
      this->accountBalance = accountBalance;
    else
    {
      this->accountBalance = 0.00;
      cout << "Account Balance is not validate" << endl;
    }
  }

  string getAccountName() // for retrieves the name of the account
  {
    return accountName;
  }

  long getAccountNo() // for retrieves the account number
  {
    return accountNumber;
  }

  double getAccountBalance() // for retrieves the balance of the account
  {
    return accountBalance;
  }

  bool checkAccountName(string accountName) // cheack validity of account name
  {
    /*The account name can only contain the following characters:
        o The letters a to z (upper and lowercase) (zero or many times)
        o The hyphen character (zero or many times)
        o The single quote character (zero or one time)
        o The space character (zero or one time)
        o The account name must be a minimum of 4 characters*/
    if (accountName.length() < 4)
      return false;
    for (int i = 0; i < accountName.length(); i++)
    {
      if (!isalpha(accountName[i]) && (accountName[i] != '-') && (accountName[i] != ' ') && accountName[i] != '\'' && (accountName[i] == '\'' && accountName[i + 1] == '\'') && (accountName[i] == ' ' && accountName[i + 1] == ' '))
        return false;
    }
    return true;
  }

  bool checkAccountNo(long accountNo) // cheack validity of account no
  {
    // The account number can only contain positive numeric values and must be between 5 and 9 digit
    if (accountNo > 9999 && accountNo < 1000000000)
      return true;
    else
      return false;
  }

  bool checkAccountBalance(double accountBalance) // cheack validity of account balance
  {
    // The account balance can contain positive and negative values but must have a maximum precision of 2 decimal places.
    double decimalPart = abs(accountBalance - trunc(accountBalance));
    int precision = 0;
    while (decimalPart > 0 && precision < 16)
    {
      decimalPart *= 10;
      decimalPart -= trunc(decimalPart);
      precision++;
    }
    if (precision < 3)
      return true;
    else
      false;
  }

  bool setAccountName(string accountName) // for updating the account name
  {
    if (checkAccountName(accountName))
    {
      this->accountName = accountName;
      return true;
    }
    return false;
  }

  bool setAccountNo(long accountNumber) // for updating the account name
  {
    if (checkAccountNo(accountNumber))
    {
      this->accountNumber = accountNumber;
      return true;
    }
    return false;
  }

  bool setAccountBalance(double accountBalance) // for updating the account name
  {
    if (checkAccountBalance(accountBalance))
    {
      this->accountBalance = accountBalance;
      return true;
    }
    return false;
  }

  string summaryAccount()
  {
    return "Account Details: " + accountName + " - " + to_string(accountNumber) + " - " + to_string(accountBalance);
  }
};

// Create the necessary instance variables. These instance variables should only be accessible inside the Bank class
class Bank
{
  string bankName;                 // It’s Bank name.
  string branchLocations[10];      // It’s Branch location
  Account accountCollections[100]; // A collection of all the Accounts created (from the Account class)

public:
  Bank()
  {
    // Leave Blank
  }

  Bank(string bankName, string branchLocations[])
  {
    if (checkBankName(bankName)) // cheack validity of bank name by the function which is define below
      this->bankName = bankName;
    else
    {
      this->bankName = "~";
      cout << " Bank Name is not validate" << endl;
    }
    if (checkBranchLocations(branchLocations)) // cheack validity of branch locations by the function which is define below
      for (int i = 0; i < 10; i++)
      {
        if (branchLocations[i] == "~")
          break;
        this->branchLocations[i] = branchLocations[i];
      }
    else
    {
      for (int i = 0; i < 10; i++)
        this->branchLocations[i] = "~";
      cout << "Please Enter Atleast 5 locations" << endl;
    }
  }

  string getBankName() // for retrieves the name of the bank
  {
    return bankName;
  }

  string *getBranchLocations() // for retrieves the branch Locations
  {
    return branchLocations;
  }

  bool checkBankName(string bankName) // cheack validity of bank name
  {
    /*It’s Bank name. The bank name can only contain alphabetical characters
      o The letters a to z (upper and lowercase) (zero or many times)
      o The numbers 0 to 9 (between zero and three times)
      o The ampersand (&) character (zero or may times)
      o The space character (zero or one time)
      o Bank name should be a minimum of 8 characters*/
    if ((bankName.length() < 8))
      return false;
    for (int i = 0; i < bankName.length(); i++)
    {
      if ((!isalpha(bankName[i])) || (bankName[i] != '&') || (bankName[i] != ' ') || (!isdigit(bankName[i])) || ((bankName[i] == ' ') && (bankName[i + 1] == ' ')))
        return false;
    }
    return true;
  }

  bool checkBranchLocations(string branchLocations[]) // cheack validity of branch locations
  {
    // Please add a minimum of 5 BranchLocations value
    for (int i = 0; i < 5; i++)
    {
      if (branchLocations[i] == "~")
        return false;
    }
    return true;
  }

  bool setBankName(string bankName)
  {
    if (checkBankName(bankName))
    {
      this->bankName = bankName;
      return true;
    }
    return false;
  }

  bool setBranchLocations(string branchLocations[])
  {
    if (checkBranchLocations(branchLocations))
    {
      for (int i = 0; i < 5; i++)
      {
        if (this->branchLocations[i] == branchLocations[i])
          return true;
      }
    }
    return false;
  }

  Account getAccount(long accountNumber)
  {
    for (int i = 0; i < 100; i++)
    {
      long AccountNumber = accountCollections[i].getAccountNo();
      if (AccountNumber == accountNumber)
        return accountCollections[i];
    }
    // return; ????
  }

  bool addAccount(long accountNumber)
  {
    int i;
    string accountName;
    for (i = 0; i < 100; i++)
    {
      long AccountNumber = accountCollections[i].getAccountNo();
      if (AccountNumber == accountNumber)
      {
        if (AccountNumber == 0)
          break;
        return false;
      }
    }
    cout << "Enter the Name: ";
    cin >> accountName;
    Account obj(accountName, accountNumber, 0.00);
    accountCollections[i] = obj;
    return true;
  }

  Account viewAccount_accountNo(long accountNumber)
  {
    for (int i = 0; i < 100; i++)
    {
      long AccountNumber = accountCollections[i].getAccountNo();
      if (AccountNumber == accountNumber)
      {
        if (AccountNumber == 0)
          break;
        return accountCollections[i];
      }
    }
    // return; ????
  }

  int viewAccount_index(long accountNumber)
  {
    for (int i = 0; i < 100; i++)
    {
      long AccountNumber = accountCollections[i].getAccountNo();
      if (AccountNumber == accountNumber)
      {
        if (AccountNumber == 0)
          break;
        return i;
      }
    }
    return (-1);
  }

  bool modifyAccount(long accountNumber)
  {
    string accountName;
    int i = viewAccount_index(accountNumber);
    if (i == -1)
      return false;
    int choice;
    cout << "1. Only Update Name";
    cout << "2. Only Update Balance";
    cout << "3. Both Update Name & Balance";
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter the Name: ";
      cin >> accountName;
      if (accountCollections[i].setAccountName(accountName))
      {
        string AccountName = accountCollections[i].getAccountName();
        AccountName = accountName;
      }
      else
        cout << "You Have Entered Invalid Name" << endl;
      break;
    case 2:
      cout << "1. Add Amount";
      cout << "2. withdrwal Amount";
      cout << "Enter Choice: ";
      cin >> choice;
      double AccountBalance = accountCollections[i].getAccountBalance();
      switch (choice)
      {
      case 1:
        if (addBalance(accountNumber))
          cout << "Balance Has Added" << endl;
        else
          cout << "You Have Entered Wrong Amount" << endl;
        cout << "Balance: " << AccountBalance << endl;
        break;
      case 2:
        if (withdrawlBalance(accountNumber))
        {
          cout << "Balance Has withdrawled" << endl;
          cout << "Balance: " << AccountBalance << endl;
        }
        else
        {
          cout << "You Have Entered Wrong Amount" << endl;
          cout << "Balance: " << AccountBalance << endl;
          break;
        }
        break;
      default:
        cout << "You Have Entered Wrong Choice" << endl;
        break;
      }
      break;
    case 3:
      cout << "Enter the Name: ";
      cin >> accountName;
      if (accountCollections[i].setAccountName(accountName))
      {
        string AccountName = accountCollections[i].getAccountName();
        AccountName = accountName;
      }
      else
      {
        cout << "You Have Entered Invalid Name" << endl;
        break;
      }
      int Choice;
      cout << "1. Add Amount";
      cout << "2. withdrwal Amount";
      cout << "Enter Choice: ";
      cin >> Choice;
      switch (Choice)
      {
      case 1:
        if (addBalance(accountNumber))
        {
          cout << "Balance Has Added" << endl;
          cout << "Balance: " << AccountBalance << endl;
        }
        else
        {
          cout << "You Have Entered Wrong Amount" << endl;
          cout << "Balance: " << AccountBalance << endl;
          break;
        }
      case 2:
        if (withdrawlBalance(accountNumber))
        {
          cout << "Balance Has withdrawled" << endl;
          cout << "Balance: " << AccountBalance << endl;
        }
        else
        {
          cout << "You Have Entered Wrong Amount" << endl;
          cout << "Balance: " << AccountBalance << endl;
          break;
        }
        break;
      default:
        cout << "You Have Entered Wrong Choice" << endl;
        break;
      }
    }
  }

  bool addBalance(long accountNumber)
  {
  }

  bool withdrawlBalance(long accountNumber)
  {
    int i = viewAccount_index(accountNumber);
    double amount;
    if (i != -1)
    {
      double balance = accountCollections[i].getAccountBalance();
      cout << "Enter the amount: ";
      cin >> amount;
      if (accountCollections[i].checkAccountBalance(amount))
      {
        balance = balance - amount;
        return true;
      }
      else
        return false;
    }
    return false;
  }

  bool deleteAccount(long accountNumber)
  {

  }
};

// main function
int main()
{
  Bank bank;
  long accountNumber;
  string branchLocations[10];
  Account accountCollections[100];
  for (int i = 0; i < 10; i++)
    branchLocations[i] = "~";

  while (1)
  {
    int choice;
    cout << "\n\n\n";
    cout << "\tEnter 1: Add Account" << endl;
    cout << "\tEnter 2: Delete the Account" << endl;
    cout << "\tEnter 3: Add Balance" << endl;
    cout << "\tEnter 4: Withdrawl Balance" << endl;
    cout << "\tEnter 5: Update Bank Account Name" << endl;
    cout << "\tEnter 6: Display Account Details" << endl;
    cout << "\tEnter 7: Display Total Balance" << endl;
    cout << "\tEnter 8: Display Details of all the accounts in the bank" << endl;
    cout << "\tEnter 9: Getting the name of the account holder" << endl;
    cout << "\tEnter 10: For existing the bank" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
      cout << "Enter all the bank detials for new account" << endl;
      bank.addAccount(accountNumber);
    }
    else if (choice == 2)
    {
      cout << "Enter your account number: ";
      cin >> accountNumber;
      cout << "Are you sure ?\n 'yes' or 'no'" << endl;
      string choice;
      cout << "\nEnter your choice: ";
      cin >> choice;
      if (choice == "yes")
        bank.deleteAccount(accountNumber);
    }
    else if (choice == 3)
    {
      cout << "Enter your account number: ";
      cin >> accountNumber;
      bank.addBalance(accountNumber);
    }
    else if (choice == 4)
    {
      cout << "Enter your account number: ";
      cin >> accountNumber;
      bank.withdrawlBalance(accountNumber);
    }
    else if (choice == 5)
    {
      cout << "Enter your account number: ";
      cin >> accountNumber;
      // bank.updateName(accountNumber);
    }
    else if (choice == 6)
    {
      cout << "Enter your account number: ";
      cin >> accountNumber;
      // bank.accountDetails(accountNumber);
    }
    else if (choice == 7)
    {
      // bank.bankBalance();
    }
    else if (choice == 8)
    {
      // bank.displayAllAccountDetails();
    }
    else if (choice == 9)
    {
      cout << "Enter your account number: ";
      cin >> accountNumber;
      // bank.getName(accountNumber);
    }
    else if (choice == 10)
    {
      cout << "\n\t~Thank You~" << endl;
      break;
    }
    else
      cout << "\t~Wrong Input~\n\tEnter your choice carefully";
  }
  return 0;
}