#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    try
    {
        std::unique_ptr<Account> barts_account = std::make_unique<Checking_Account>("Bart", -10.0);
        std::cout << *barts_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    try
    {
        std::unique_ptr<Account> simpsons_account = std::make_unique<Checking_Account>("Simpson", 10.0);
        std::cout << simpsons_account->withdraw(20) << std::endl;
    }
    catch (const InsufficentFundsException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
