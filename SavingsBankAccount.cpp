#include "SavingsBankAccount.h"

SavingsBankAccount::SavingsBankAccount(string id, double balance)
{
    ptr= nullptr;
    if(balance<1000){
        cout<<"At least u must save more than 100 $";
        return;
    }
    else{
        ID = std::move(id);
        this->balance = balance ;
    }
}

void SavingsBankAccount::set_ptr(  Client *a) {
    ptr = a;
}

double SavingsBankAccount::get_balance(){
    return balance;
}


bool SavingsBankAccount::withdraw(double x){
    if (balance-1000>=x){
        balance -=  x;
        return true;
    }
    return false;
}

void SavingsBankAccount::deposit(double x){
    if(x>=100)
        balance +=x;
    else{
        cout<<"u must at least deposit more than 100 $_$\n";
    }
}


void SavingsBankAccount::set_id(string s) {
    BankAccount::set_id(s);
}


void SavingsBankAccount::set_balance(double s) {
    BankAccount::set_balance(s);
}
