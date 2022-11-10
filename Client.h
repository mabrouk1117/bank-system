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
        BankAccount *ptr ;
    public:
        Client(string n , string id , string phone , string address ) ;
        void set_ptr(  BankAccount &) ;
        string get_name();



};

#endif // CLIENT_H
