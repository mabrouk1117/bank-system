#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Client.h"

using namespace std;
class Client ;
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

    __attribute__((unused)) virtual bool withdraw       (double x) ;
    virtual void deposite       (double x) ;
    virtual void set_id         (string s)  ;
    virtual void set_balance    (double s)  ;
    BankAccount()= default;
    ~BankAccount()= default;
};


class SavingsBankAccount: public BankAccount{
public:
    __attribute__((unused)) SavingsBankAccount(string id , double balance);
    void    set_ptr         (Client *) override ;
    double  get_balance     ()         override ;
    bool    withdraw        (double x) override ;
    void    deposite        (double x) override ;
    void    set_id          (string s) override ;
    void    set_balance     (double s) override ;


};
#endif // BANKACCOUNT_H
