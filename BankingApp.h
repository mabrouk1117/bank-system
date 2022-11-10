#ifndef BANKINGAPP_H
#define BANKINGAPP_H
#include "BankAccount.h"
using namespace std ;

class BankingApp
{
    private:
        map<int , Client > clients;
    public:
        BankingApp();
        ~BankingApp();
        void menu();
        void addAccount() ;
};

#endif // BANKINGAPP_H
