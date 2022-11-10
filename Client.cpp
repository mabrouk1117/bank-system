#include "Client.h"

Client::Client(string n , string id , string phone , string address )
{
    name = n ;
    ID = id ;
    this ->phone = phone ;
    this ->address = address ;
    ptr = NULL ;
}


void Client::set_ptr( BankAccount &a) {
    ptr = &a;
}


string Client::get_name() {
    return name;
}
