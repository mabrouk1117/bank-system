#include "BankingApp.h"

void BankingApp::menu(){
    cout<<"welcome \n";
    cout<<"to add acc enter 1\nif you want to login enter 2\n";
    int x;
    cin>>x;
    if (x == 1){
        addAccount();
    }
    if (x==2){
        string id;
        cin>>id;
        cout<<"if you want to deposite enter 1\n";
        cin>>x;
        if (x==1){
            cout<<"enter the amount of money\n";
            double money;
            cin>>money ;
            accounts[stoi(id)-1].deposite(money);
            cout<<(*clients[stoi(id)-1].ptr).get_balance()<<endl;
        }

    }
    if (x == 3){
        for(auto i:clients){
            cout<<i.get_name()<<endl;
        }
    }
}


void BankingApp::addAccount(){
    cout<<"if u want it saving account enter 2 otherwise enter 1";
    int k ;     cin>>k;
    cout<<"Enter the Account data\n";
    string name ,phone,address;
    double balance ;
    int ID ;
    cout<<"Name >> Phone number >> Address >> Balance";
    cin>>name>>phone>> address>>balance ;
    ID = clients.size()+1;
    string id = to_string(ID) ;
    cout<<"YOUR ID IS "<<id<<endl;
    Client c(name,id,phone,address );

    BankAccount b(id,balance);



    clients.push_back(c) ;
    accounts.push_back(b) ;
    c.set_ptr(&accounts.back()) ;
    clients.back() = c ;
    b.set_ptr(& clients.back()) ;
    accounts.back() = b ;

}


