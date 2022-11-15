#ifndef PROBLEM_SOLVING_SAVINGSBANKACCOUNT_H
#define PROBLEM_SOLVING_SAVINGSBANKACCOUNT_H
#include "BankAccount.h"


class SavingsBankAccount: public BankAccount{
public:
    SavingsBankAccount(string id , double balance);
    void    set_ptr         (Client *) override ;
    double  get_balance     ()         override ;
    bool    withdraw        (double x) override ;
    void    deposit         (double x) override ;
    void    set_id          (string s) override ;
    void    set_balance     (double s) override ;


};
#endif //PROBLEM_SOLVING_SAVINGSBANKACCOUNT_H
