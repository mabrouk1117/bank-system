#ifndef BANKINGAPP_H
#define BANKINGAPP_H
#include "BankAccount.h"
#include "SavingsBankAccount.h"
using namespace std ;

class BankingApp
{
private:
//    map<string , Client> client;
    vector<Client>clients;
    vector<BankAccount>accounts;
    vector<SavingsBankAccount>Savings;
public:
    BankingApp()= default;
    ~BankingApp()= default;

    void menu();
    void addAccount() ;
};

#endif // BANKINGAPP_H
