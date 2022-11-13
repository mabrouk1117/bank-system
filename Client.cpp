#include "Client.h"

#include <utility>

Client::Client(string n , string id , string phone , string address )
{
    name = std::move(n) ;
    ID = std::move(id) ;
    this ->phone = std::move(phone) ;
    this ->address = std::move(address) ;

    ptr = nullptr ;
}


void Client::set_ptr( BankAccount *a) {
    this->ptr = a;
}


string Client::get_name() {
    return name;
}

BankAccount* Client::get_ptr() const {
    return ptr ;
}
