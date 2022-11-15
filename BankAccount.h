#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "Client.h"

using namespace std;

class BankAccount
{
protected:
    string ID;
    double balance{} ;
    Client * ptr{} ;
public:
    BankAccount(string id , double balance);

    virtual void set_ptr(  Client *) ;

    virtual double get_balance();

    virtual bool withdraw       (double x) ;
    virtual void deposit       (double x) ;
    virtual void set_id         (string s)  ;
    virtual void set_balance    (double s)  ;
    BankAccount()= default;
    ~BankAccount()= default;
};


#endif // BANKACCOUNT_H
