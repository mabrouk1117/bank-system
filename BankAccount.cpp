#include "BankAccount.h"

BankAccount::BankAccount(string id , double balance)
{
    ID =id;
    this->balance = balance ;
    ptr= NULL;
}

void BankAccount::set_ptr(  Client &a) {
    ptr = &a;
}

bool BankAccount::withdraw(double x){
    if (balance>=x){
        balance-=x;
        return 1;
    }
    return 0;
}

void BankAccount::deposite(double x){
    balance +=x;
}
