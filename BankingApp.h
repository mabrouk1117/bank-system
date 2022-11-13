#ifndef BANKINGAPP_H
#define BANKINGAPP_H
#include "BankAccount.h"
using namespace std ;

class BankingApp
{
private:
    vector<Client>clients;
    vector<BankAccount>accounts;
    vector<SavingsBankAccount>Savings;
public:
    BankingApp(){};
    ~BankingApp(){}

    __attribute__((unused)) void menu();
    void addAccount() ;
};

#endif // BANKINGAPP_H
