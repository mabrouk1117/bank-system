#include "BankingApp.h"

BankingApp::BankingApp()
{
    // load data
}

BankingApp::~BankingApp()
{
    // save data
}

void BankingApp::menu(){
    cout<<"welcome \n";
    cout<<"to add acc enter 1\nif you want to login enter 2\n";
    int x;
    cin>>x;
    if (x == 1){
        addAccount();
    }
    if (x == 3){
        for(auto i:clients){
            cout<<i.first<<"  "<<i.second.get_name();
        }
    }
}

void BankingApp::addAccount(){
    cout<<"enter data \n";
    string name ,phone,address;
    double balance ;
    int ID ;
    cin>>name>>phone>> address>>balance ;
    ID = clients.size()+1;
    string id = to_string(ID) ;
    Client c(name,id,phone,address);

    BankAccount b(id,balance);
    c.set_ptr(b);
    b.set_ptr(c);
    clients.insert(make_pair(ID,c));


}







