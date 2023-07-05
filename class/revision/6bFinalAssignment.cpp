#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Create the necessary instance variables. These instance variables should only be accessible inside the Account class.
class Account
{
  string accountName;    // An account name(account holder name).
  string accountNumber;  // An account number, which will be a whole number.
  string accountBalance; // An account balance representing a quantity of cash.

public:
  Account()
  {
    // Leave Blank
  }

  // Constructor--> Sets the instance variables of the class and Limitations of instance variables must be imposed
  Account(string accountName, string accountNumber, string accountBalance)
  {
    this->accountName = accountName;
    this->accountNumber = accountNumber;
    this->accountBalance = accountBalance;
  }

  string getAccountName() // for retrieves the name of the account
  {
    return accountName;
  }

  string getAccountNo() // for retrieves the account number
  {
    return accountNumber;
  }

  string getAccountBalance() // for retrieves the balance of the account
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

  bool checkAccountNo(string accountNo) // cheack validity of account no
  {
    // The account number can only contain positive numeric values and must be between 5 and 9 digit
    long long AccountNo = stoi(accountNo);
    if (AccountNo > 0 && accountNo.length() > 4 && accountNo.length() < 10)
      return false;
    for (int i = 0; i < accountNo.length(); i++)
    {
      if (!isdigit(accountNo[i]))
        return false;
    }
    return true;
  }

  bool checkAccountBalance(string accountBalance) // cheack validity of account balance
  {
    // The account balance can contain positive and negative values but must have a maximum precision of 2 decimal places.
    for (int i = 0; i < accountBalance.length(); i++)
    {
      if (!isdigit(accountBalance[i]) && accountBalance[i] != '.' && accountBalance[i] != '-' && accountBalance[i] != '+')
        return false;
    }
    return ((accountBalance.substr(accountBalance.find('.') + 1).length()) < 3) ? true : false;
  }

  // another method---->>>
  /*bool checkAccountBalance(double accountBalance) // cheack validity of account balance
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
  }*/

  bool setAccountName(string accountName) // for updating the account name
  {
    if (checkAccountName(accountName))
    {
      this->accountName = accountName;
      return true;
    }
    return false;
  }

  bool setAccountNo(string accountNumber) // for updating the account name
  {
    if (checkAccountNo(accountNumber))
    {
      this->accountNumber = accountNumber;
      return true;
    }
    return false;
  }

  bool setAccountBalance(string amount, int choice) // for updating the account name
  {
    if (checkAccountBalance(amount))
    {
      double accountBalance = stod(this->accountBalance);
      (choice == 1) ? accountBalance += stod(amount) : accountBalance -= stod(amount);
      this->accountBalance = to_string(accountBalance);
      return true;
    }
    return false;
  }

  bool equals(Account obj) // returns a Boolean value of whether one object is equal in VALUE to an account object
  {
    return ((accountNumber == obj.getAccountNo()) && (accountName == obj.getAccountName()) && (accountBalance == obj.getAccountBalance())) ? true : false;
  }

  string toString() // returns a string summary of the account
  {
    return "Account Details: " + accountName + " - " + accountNumber + " - " + accountBalance;
  }
};

// Create the necessary instance variables. These instance variables should only be accessible inside the Bank class
class Bank
{
  string bankName;                 // It’s Bank name.
  string branchLocations[10];      // It’s Branch location
  Account accountCollections[100]; // A collection of all the Accounts created (from the Account class)
  int index = -1;
  int indexLoc = -1;

public:
  Bank()
  {
    // Leave Blank
  }

  // Constructor--> Sets the instance variables of the class and Limitations of instance variables must be imposed
  Bank(string bankName, string branchLocations[], int noOfLocations)
  {
    this->bankName = bankName;
    for (int i = 0; i < noOfLocations; i++)
      this->branchLocations[i] = branchLocations[i];
    indexLoc = noOfLocations - 1;
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
      if ((!isalpha(bankName[i])) && (bankName[i] != '&') && (bankName[i] != ' ') && (!isdigit(bankName[i])) && ((bankName[i] == ' ') && (bankName[i + 1] == ' ')))
        return false;
    }
    return true;
  }

  bool checkBranchLocations(string branchLocations[]) // cheack validity of branch locations
  {
    // Please add a minimum of 5 BranchLocations value
    for (int i = 0; i < indexLoc; i++)
    {
      if (branchLocations[i] == "~")
        return false;
    }
    return true;
  }

  bool setBankName(string bankName)
  {
    // returns a Boolean value representing whether the bank name has been updated only updates the name of the bank if it is valid
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
      for (int i = 0; i < indexLoc; i++)
      {
        if (this->branchLocations[i] == branchLocations[i])
          return true;
      }
    }
    return false;
  }

  Account getAccount(string accountNumber)
  {
    Account obj; // empty constructor
    for (int i = 0; i <= index; i++)
    {
      if (accountCollections[i].getAccountNo() == accountNumber)
        return accountCollections[i];
    }
    return obj; // return empty constructor when account is not found
  }

  // Adds Account to the collections of accounts.
  bool addAccount(string accountNumber)
  {
    int i;
    string accountName;
    if (index == 100)
      return false;
    for (i = 0; i <= index; i++) // account number must be unique in the Bank to be added to the collections of accounts
    {
      if (accountCollections[i].getAccountNo() == accountNumber) // If account number is NOT unique in bank collection of accounts, account is not added
        return false;
    }
    cout << "\tEnter the Name: ";
    cin >> accountName;
    Account obj(accountName, accountNumber, "0.00");
    accountCollections[++index] = obj;
    return true; // returns a Boolean value representing if the account has been added to the list of bank accounts.
  }

  Account viewAccount_accountNo(string accountNumber)
  {
    Account obj; // empty constructor
    for (int i = 0; i <= index; i++)
    {
      if (accountCollections[i].getAccountNo() == accountNumber)
        return accountCollections[i];
    }
    return obj; // return empty constructor when account is not found
  }

  Account viewAccount_index(int index)
  {
    Account obj; // if at that index any account is exist return acocunt if not so return empty by default constructor
    return (this->index < index) ? obj : accountCollections[index];
  }

  bool modifyAccount(string accountNumber)
  {
    int i;
    for (i = 0; i <= index; i++)
    {
      if (accountCollections[i].getAccountNo() == accountNumber)
        break;
    }
    if (i == index) // if account is not found
      return false;

    int Choice;
    cout << "\n1. Only Update Name";
    cout << "2. Only Update Balance";
    cout << "3. Both Update Name & Balance";
    cout << "\tEnter Choice: ";
    cin >> Choice;

    if (Choice == 1 || Choice == 3)
    {
      string accountName;
      cout << "\tEnter the Name: ";
      cin >> accountName;
      if (accountCollections[i].setAccountName(accountName))
        cout << "\n\tName has updated" << endl;
      else
        cout << "\n\tYou Have Entered Invalid Name" << endl;
    }
    if (Choice == 2 || Choice == 3)
    {
      int choice;
      cout << "\n1. Add Amount" << endl;
      cout << "2. withdrwal Amount" << endl;
      cout << "\tEnter Choice: ";
      cin >> choice;
      string amount;
      cout << "\tEnter the Amount: ";
      cin >> amount;
      if (accountCollections[i].setAccountBalance(amount, choice))
        cout << "\n\tAmount has updated" << endl;
      else
        cout << "\n\tYou Have Entered Invalid Amount" << endl;
    }
    if (Choice != 1 && Choice != 2 && Choice != 3)
    {
      cout << "\n\tYou Have Entered Invalid Choice" << endl;
      return false;
    }
    return true;
  }

  // delete the account by searching the list of accounts by account number.
  bool deleteAccount_accountNo(string accountNumber)
  {
    int i;
    string accountName;
    for (i = 0; i <= index; i++) // account number must be unique in the Bank to be added to the collections of accounts
    {
      if (accountCollections[i].getAccountNo() == accountNumber) // Deletes the account if found
      {
        accountCollections[i] = accountCollections[index];
        index--;
        return true;
      }
    }
    return false;
  }

  // delete the account by searching the list of accounts by the index number.
  bool deleteAccount_index(int index)
  {
    if (this->index < index) // Deletes the account if found
      return false;
    accountCollections[index] = accountCollections[this->index];
    this->index--;
    return true;
  }

  // display the accounts
  bool displayAccount(string accountNumber)
  {
    for (int i = 0; i <= index; i++)
    {
      if (accountCollections[i].getAccountNo() == accountNumber)
      {
        accountCollections[i].toString(); // printig account details
        return true;
      }
    }
    return false;
  }

  // display all the accounts
  void displayAllAccounts()
  {
    displayBranchLocations();
    for (int i = 0; i <= index; i++)
    {
      cout << "\n\n\t\t" << i + 1 << ".";
      accountCollections[i].toString();
    }
  }

  // add branch locations
  bool addBranchLocations(string location)
  {
    if (indexLoc == 9) // if locations reached the maximum size of array
      return false;
    branchLocations[++indexLoc] = location;
    return true;
  }

  // display all brnach locations
  void displayBranchLocations()
  {
    if (indexLoc == 9) // if locations reached the maximum size of array
    {
      cout << "You have reached maximum locations" << endl;
      return;
    }
    cout << "\n\n\t\tBranch Locations: ";
    for (int i = 0; i < indexLoc; i++)
    {
      cout << i + 1 << branchLocations[i] << ", ";
    }
    if (index == -1) // if there is no loctions added in a bank
      cout << "\nNo Accounts in Bank" << endl;
  }
};

// main function
int main()
{
  Bank bank;
  Bank bankCollections[100];
  int index = -1;
  string branchLocations1[] = {"Mumbai, Maharashtra", "Chennai, Tamil Nadu", "Kolkata, West Bengal", "New Delhi, Delhi", "Bengaluru, Karnataka"}; // It’s Branch location
  Bank bank1("State Bank of India (SBI)", branchLocations1, 5);
  string branchLocations2[] = {"Mumbai, Maharashtra", "Chennai, Tamil Nadu", "Kolkata, West Bengal", "New Delhi, Delhi", "Hyderabad, Telangana"}; // It’s Branch location
  Bank bank2("HDFC Bank", branchLocations2, 5);
  string branchLocations3[] = {"Mumbai, Maharashtra", "Chennai, Tamil Nadu", "Kolkata, West Bengal", "New Delhi, Delhi", "Bengaluru, Karnataka"}; // It’s Branch location
  Bank bank3("ICICI Bank", branchLocations3, 5);
  string branchLocations4[] = {"Mumbai, Maharashtra", "Chennai, Tamil Nadu", "Kolkata, West Bengal", "New Delhi, Delhi", "Ahmedabad, Gujarat"}; // It’s Branch location
  Bank bank4("Punjab National Bank (PNB)", branchLocations4, 5);
  string branchLocations5[] = {"Mumbai, Maharashtra", "Chennai, Tamil Nadu", "Kolkata, West Bengal", "New Delhi, Delhi", "Vadodara, Gujarat"}; // It’s Branch location
  Bank bank5("Bank of Baroda (BOB)", branchLocations5, 5);

  bankCollections[0] = bank1;
  index++;
  bankCollections[1] = bank2;
  index++;
  bankCollections[2] = bank3;
  index++;
  bankCollections[3] = bank4;
  index++;
  bankCollections[4] = bank5;
  index++;

  while (1)
  {
    int choice, Choice;
    cout << "\n\n\n";

    cout << "\tEnter 1: Add Account" << endl;
    cout << "\tEnter 2: Delete the Account" << endl;
    cout << "\tEnter 3: Update Account" << endl;
    cout << "\tEnter 4: Display Account Details" << endl;
    cout << "\tEnter 5: Display Details of all the accounts in the bank" << endl;
    cout << "\tEnter 6: Add Branch Location" << endl;
    cout << "\tEnter 7: Display all branch locations" << endl;
    cout << "\tEnter 8: Display Details of all the bank" << endl;
    cout << "\tEnter 9: For existing the bank" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
    {
      cout << "1. State Bank of India (SBI)" << endl;
      cout << "2. HDFC Bank" << endl;
      cout << "3. ICICI Bank" << endl;
      cout << "4. Punjab National Bank (PNB)" << endl;
      cout << "5. Bank of Baroda (BOB)" << endl;
      cout << "\tSelect Bank: ";
      cin >> Choice;
      if (Choice == 1)
        bank = bank1;
      else if (Choice == 2)
        bank = bank2;
      else if (Choice == 3)
        bank = bank3;
      else if (Choice == 4)
        bank = bank4;
      else if (Choice == 5)
        bank = bank5;
      else
        cout << "\n\n\t\t~Invalid Choice~" << endl;

      if (choice == 1) // add account
      {
        cout << "Enter the Account Number: ";
        string accountNumber;
        cin >> accountNumber;
        if (bank.addAccount(accountNumber))
          cout << "\n\tAccount has been added" << endl;
        else
          cout << "\n\tYou Have Entered Invalid Account Number or Account Number is already exist" << endl;
      }
      else if (choice == 2) // Delete the Account
      {
        cout << "Enter the Account Number: ";
        string accountNumber;
        cin >> accountNumber;
        if (bank.deleteAccount_accountNo(accountNumber))
          cout << "\n\tAccount has been deleted" << endl;
        else
          cout << "\n\tYou Have Entered Invalid Account Number" << endl;
      }
      else if (choice == 3) // Update Account
      {
        cout << "Enter the Account Number: ";
        string accountNumber;
        cin >> accountNumber;
        if (bank.modifyAccount(accountNumber))
          cout << "\n\tAccount has been updated" << endl;
        else
          cout << "\n\tYou Have Entered Invalid Account Number" << endl;
      }
      else if (choice == 4) // Display Account Details
      {
        cout << "Enter the Account Number: ";
        string accountNumber;
        cin >> accountNumber;
        if (bank.displayAccount(accountNumber))
          cout << "\n\tAccount has been displayed" << endl;
        else
          cout << "\n\tYou Have Entered Invalid Account Number or reached maximim accounts" << endl;
      }
      else if (choice == 5) // Display Details of all the accounts in the bank
      {
        string bankName = bank.getBankName();
        cout << "Bank Name: " << bankName;
        bank.displayAllAccounts();
      }
    }
    else if (choice == 6) // Add Branch Location
    {
      cout << "Enter the Branch Location: ";
      string location;
      cin >> location;
      if (bank.addBranchLocations(location))
        cout << "\n\tBranch Location has been added" << endl;
      else
        cout << "You have reached maximum locations" << endl;
    }
    else if (choice == 7) // Display all branch locations
      bank.displayBranchLocations();
    else if (choice == 8) // Display Details of all the bank
    {
      for (int i = 0; i <= index; i++)
      {
        string bankName = bankCollections[i].getBankName();
        cout << "\n\n\n\t" << i + 1 << "Bank Name: " << bankName;
        bankCollections[i].displayAllAccounts();
      }
    }
    else if (choice == 9) // For existing the bank
    {
      cout << "\t\t~~Thank You~~\n\n\n";
      break;
    }
    else // if you entered wrong choice
    {
      cout << "\n\tYou Have Entered Invalid Choice";
      cout << "\n\tTry Again" << endl;
    }

    return 0;
  }
}

// Errors:---->>>
// In this program we can also add a functions for adding bank also;
// In this program we have to pass the only one branch loction from the main function after choosing the branch location from the specified bank
// so in the we can only store account in specified locations