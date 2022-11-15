#ifndef CLIENT_H
#define CLIENT_H
#include<bits/stdc++.h>
using namespace std;

class BankAccount ;
class SavingsBankAccount ;

class Client
{
private:
    string name ;
    string ID;
    string phone;
    string address;
    int type{};

public:

    BankAccount *ptr ;
    SavingsBankAccount *pointer ;
    Client(string n , string id , string phone , string address) ;
    void set_ptr(  BankAccount *) ;
    void set_pointer( SavingsBankAccount *) ;
    BankAccount* get_ptr() const ;
    string get_name();
    string get_address();
    string get_phone();
    int get_type() const;

};

#endif // CLIENT_H
