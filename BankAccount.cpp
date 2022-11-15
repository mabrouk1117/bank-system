#include "BankAccount.h"


BankAccount::BankAccount(string id , double balance)
{
    ID =std::move(id);
    this->balance = balance ;
    ptr= nullptr;
}

void BankAccount::set_ptr(  Client *a) {
    ptr = a;
}
double BankAccount::get_balance(){
    return balance;
}

bool BankAccount::withdraw(double x){
    if (balance>=x){
        balance-=x;
        return true;
    }
    return false;
}

void BankAccount::deposit(double x){
    balance +=x;
}

void BankAccount::set_id(string s) {
    ID = std::move(s);
}

void BankAccount::set_balance(double s) {
    balance = s;
}
