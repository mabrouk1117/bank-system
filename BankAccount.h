#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Client.h"

using namespace std;

class BankAccount
{
    private:
        string ID;
        double balance ;
        Client * ptr ;
    public:
        BankAccount(string id , double balance);
        void set_ptr(  Client *) ;
        double get_balance();
        virtual bool withdraw(double x) ;
        virtual void deposite(double x) ;
};

#endif // BANKACCOUNT_H
