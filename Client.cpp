#include "Client.h"

#include <utility>

Client::Client(string n , string id , string phone , string address ):ID(std::move(id))
{
    name = std::move(n) ;
    //ID = std::move(id) ;
    this ->phone = std::move(phone) ;
    this ->address = std::move(address) ;

    ptr = nullptr ;
    pointer = nullptr ;
}


void Client::set_ptr( BankAccount *a) {
    type = 0;
    this->ptr = a;
}
void Client::set_pointer(SavingsBankAccount *a) {
    type = 1;
    this->pointer = a;
}


string Client::get_name() {
    return name;
}

BankAccount* Client::get_ptr() const {
    return ptr ;
}

string Client::get_phone() {
    return this->phone;
}

string Client::get_address() {
    return this->address;
}

int Client::get_type() const {
    return type;
}


