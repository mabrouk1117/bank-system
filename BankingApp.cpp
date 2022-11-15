#include "BankingApp.h"

void BankingApp::menu(){
    ff:
    cout<<"Welcome to FCAI Banking Application \n"
          "1. Create a New Account \n"
          "2. List Clients and Accounts \n"
          "3. Withdraw Money \n"
          "4. Deposit Money\n "
          "5. exit\n";
    cout<<"Please Enter Choice>>>>>>";
    int choice;cin>>choice;
    if(choice>5 || choice<1){
        cout<<"\n invalid choice choose another one\n";
        goto ff;
    }
    if (choice == 1){
        addAccount();
    }

    if (choice == 2){
        for(int i = 0 ; i < clients.size() ; i ++){

            cout<<"\n----------"<<clients[i].get_name()<<"--------"<<endl;
            cout<<"Address:"<<clients[i].get_address()<<endl;
            cout<<"Phone:"<<clients[i].get_phone()<<endl;
            cout<<"ID :"<<i+1<<endl;
            if(clients[i].pointer== nullptr){
                cout<<"Balance :"<<clients[i].ptr->get_balance()<<endl;
            }
            else{
                cout<<"Balance :"<<clients[i].pointer->get_balance()<<endl;
            }
        }
    }


    if (choice==3){
        gg:
        cout<<"\nPlease Enter Account ID =========>";
        int i;      cin>>i;
        i--;
        if(i>clients.size()){
            cout<<"invalid ID"<<endl;
            int y ;cin>>y;
            cout<<"\n If u want to back to the menu press 5";
            if(y == 5 ) {
                this->menu();
                return;
            }
            else
                goto gg;
        }
        cout<<"Account ID:"<<i+1;
        if(clients[i].pointer== nullptr){
            cout<<"\nAccount Type: Basic\n";
            cout<<"Balance :"<<clients[i].ptr->get_balance()<<endl;
        }
        else{
            cout<<"Account Type: Saving\n";
            cout<<"Balance :"<<clients[i].pointer->get_balance()<<endl;
        }
        start:
        cout<<"Please Enter The Amount to Withdraw =========>";
        double x ; cin>>x;

        if(clients[i].pointer== nullptr){
            if(!clients[i].ptr->withdraw(x)){
                cout<<"this is to much u dont have enough balance\n";
                goto start;
            }
        }
        else{
            if(!clients[i].pointer->withdraw(x)){
                cout<<"this is to much u dont have enough balance\n";
                goto start;
            }
        }

        cout<<"\nThanks da yo .";
        cout<<"\nNew balance :";
        if(clients[i].pointer== nullptr){
            cout<<clients[i].ptr->get_balance()<<endl;
        }
        else{
            cout<<clients[i].pointer->get_balance()<<endl;
        }

    }
    if(choice==4){
        cout<<"\nPlease Enter Account ID =========>";
        int i;      cin>>i;
        cout<<"Account ID:"<<i;
        if(clients[i].pointer== nullptr){
            cout<<"\nAccount Type: Basic\n";
            cout<<"Balance :"<<clients[i].ptr->get_balance()<<endl;
        }
        else{
            cout<<"Account Type: Saving\n";
            cout<<"Balance :"<<clients[i].pointer->get_balance()<<endl;
        }
        cout<<"Please Enter The Amount to deposit =========>";
        double x ; cin>>x;
        if(clients[i].pointer== nullptr){
            clients[i].ptr->deposit(x);
        }
        else{
            clients[i].pointer->deposit(x);
        }
        cout<<"\nThanks da yo .";
        cout<<"\nNew balance :";
        if(clients[i].pointer== nullptr){
            clients[i].ptr->get_balance();
        }
        else{
            clients[i].pointer->get_balance();
        }
    }
    if(choice == 5){
        cout<<"\nThanks for using our Bank .";
        return;
    }
}


void BankingApp::addAccount(){
    string name ,phone,address;
    cout<<"Please Enter Client User Name =========>";
    cin.clear();
//    cin.ignore();
    cin.sync();
    getline(cin,name);
    cout<<"\nPlease Enter Client Address =======>";
    cin.clear();
//    cin.ignore();
    cin.sync();
    getline(cin,address);
    cout<<"\nPlease Enter Client Phone =======>";
    cin.clear();
//    cin.ignore();
    cin.sync();
    getline(cin,phone);


    cout<<"\nWhat Type of Account Do You Like? (1) Basic (2) Saving  Type 1 or 2 =========>";
    int choice ;    cin>>choice;

    while(choice >2 || choice<1){
        cout<<"Please renter available choice 1 or 2 \n";
        cin>>choice;
    }
    cout<<"\nPlease Enter the Starting Balance =========>";
    double balance; cin>>balance;


    unsigned long long ID ;
    ID = clients.size()+1;
    string id = to_string(ID) ;
    cout<<"Your id is :"<<id;
    cout<<endl;
    if(choice==1){
        Client c(name, id, phone, address );
        BankAccount b(id,balance);
        //client.insert({name,c});
        clients.push_back(c) ;
        accounts.push_back(b) ;
        c.set_ptr( & accounts.back() ) ;//last account made
        clients.back() = c ;
        b.set_ptr(& clients.back()) ;
        accounts.back() = b ;
        cout<<"\nAn account was created with ID and Starting Balance "<<balance;
    }
    if(choice==2){
        Client c(name,id,phone,address );
        SavingsBankAccount b(id,balance);
        //client.insert({name,c});
        clients.push_back(c) ;
        Savings.push_back(b) ;
        c.set_pointer( & Savings.back() ) ;//last account made
        clients.back() = c ;
        b.set_ptr(& clients.back()) ;
        Savings.back() = b ;
        cout<<"\nAn account was created with ID FCAI-001 and Starting Balance "<<balance;
    }


}

