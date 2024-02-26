// Section 15
// Challenge
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking

    vector<Checking_Account> chck_accounts;
    chck_accounts.push_back(Checking_Account{});
    chck_accounts.push_back(Checking_Account{"Superman"});
    chck_accounts.push_back(Checking_Account{"Batman", 2000});
    chck_accounts.push_back(Checking_Account{"Wonderwoman", 5000});

    display(chck_accounts);
    deposit(chck_accounts, 1000);
    withdraw(chck_accounts, 2000);

    // Trust

    vector<Trust_Account> tru_accounts;
    tru_accounts.push_back(Trust_Account{});
    tru_accounts.push_back(Trust_Account{"Superman"});
    tru_accounts.push_back(Trust_Account{"Batman", 2000});
    tru_accounts.push_back(Trust_Account{"Wonderwoman", 5000, 5.0});

    display(tru_accounts);
    deposit(tru_accounts, 5000);
    withdraw(tru_accounts, 20);
    withdraw(tru_accounts, 20);
    withdraw(tru_accounts, 20);
    withdraw(tru_accounts, 20);

    // Overloaded constructors
    tru_accounts[0] += 3000;
    tru_accounts[1] -= 2000;
    display(tru_accounts);

    return 0;
}
