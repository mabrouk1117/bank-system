#ifndef CLIENT_H
#define CLIENT_H
#include<bits/stdc++.h>
using namespace std;

class BankAccount ;

class Client
{
    private:
        string name ;
        string ID;
        string phone;
        string address;
    public:
        BankAccount *ptr ;
        Client(string n , string id , string phone , string address ) ;
        void set_ptr(  BankAccount *) ;
        BankAccount* get_ptr() ;
        string get_name();

};

#endif // CLIENT_H
