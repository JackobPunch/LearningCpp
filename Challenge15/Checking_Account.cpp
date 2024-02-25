#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
    : Account{name, balance}, fee{fee}
{
}

// Withdraw:
//      Every withdrawal transaction will be assessed pervious mentioned flat fee

bool Checking_Account::withdraw(double amount)
{
    amount += fee;
    return Account::withdraw(amount);
}