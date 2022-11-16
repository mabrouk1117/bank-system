// FCAI - Object Oriated Programming - 2022 - Assignment 2
// Program Name : Task 4
// Author : Momen Mostafa Mabrouk   ID: 20210416   Group: A
// ver1 of Date : 11th November 2022
// section : 5

#include <bits/stdc++.h>
using namespace std;

string upload(string &t){

    int x= t.find(' ');
    string temp = t.substr(0,x);
    t = t.substr(x+1,t.size()-(x+1));
    return temp ;
}

string FitString(string input){
    string output ;
    for(int i=0;i<=input.length();i++)
    {
        if (input[i] == ' ')
        {
          if (input[i+1] == ' ')
              continue;
          else
            output+=' ';
        }
        else
            output +=input[i];
    }
    return output ;
}



class process{
public:

    string ImageName ;
    int PID;
    string SessionName;
    int SessionNumber;
    int MemUsage ;

    friend class tasklist;
    friend bool compareByName(process,process);
    friend bool compareByPID(process,process);
    friend bool compareByMem(process,process);
//friend void sorting(taskList& taskVec);
};



bool compareByName( process &a,  process &b)
{
    return a.ImageName < b.ImageName ;
}

bool compareByPID(const process &a, const process &b)
{
    return (a.PID) < (b.PID);
}


bool compareByMem( const process &a, const process &b)
{
    return a.MemUsage < b.MemUsage ;
}


class tasklist{
public:
    vector<process>vec;



void runCommand(){
    string filepath = "";
    filepath += __FILE__ ;
    cout<<filepath<<endl;
    filepath = filepath.substr(0, filepath.rfind("\\"));
    filepath +="\\info.txt";
    cout<<filepath<<endl;
    filepath = "tasklist >" + filepath ;
    const char * command = filepath.c_str() ;
    system(command) ;
}

void save(){
    fstream file;
    file.open("info.txt" , ios::in);
    string x ;
    getline(file,x);
    getline(file,x);
    getline(file,x);
    int ctr=1;
    while(1){
        string t ;
        process p ;

        getline(file , t);
        if (t.size()<20)
            break ;
        int i;
        for( i=0;i<t.size();i++){
            if (t[i]==' ' && isdigit(t[i+1]))
                break;
            p.ImageName+=t[i];
        }
        //cout<<t<<endl;
        string temp="";
        t= t.substr(i+1,t.size()-i);
        //cout<<t<<endl;
        t = FitString(t);
        //cout<<t<<endl;

        p.PID =stoi(upload(t));
        //cout<<t<<endl;
        //cout<< p.PID<<endl;
        p.SessionName = upload(t);
        //cout<<t<<endl;
        p.SessionNumber = stoi(upload(t));
        //cout<<t<<endl;

        string x =  upload(t);

        //cout<<x<<endl;
        for(int j=0;j<x.size();j++){
            if (isdigit(x[j]))
                temp+=x[j];
        }
        //cout<<temp<<endl;
        p.MemUsage = stoi(temp);
        //cout<<ctr<<" "<<p.ImageName<<" "<<p.PID<<" "<<p.SessionName<<" "<<p.SessionNumber<<" "<<p.MemUsage<<endl;
        vec.push_back(p);
        ctr++;
    }

}

void display(){
        cout<<"  ImageName                                  PID    SessionName    SessionNumber   MemUsage\n";
        cout<<"--------------------------------------------------------------------------------\n";
        for(int i=0;i<vec.size();i++){
            cout<<i<<"- "<<vec[i].ImageName<<"            "<<vec[i].PID<<"         "<<vec[i].SessionName<<"     "<<vec[i].SessionNumber  <<"      "<<vec[i].MemUsage<<" k"<<endl;
        }
}



void sortit(){
    int choice;
    cout<<"choose a way of sorting 1-by name \n2-by PID \n3-by memory usage\n";
    cin>>choice;
    if(choice==1)
    {
           sort(vec.begin(), vec.end(), compareByName);
    }
   else if(choice==2)
    {
        sort(vec.begin(), vec.end(), compareByPID);
    }
    else if(choice==3)
    {
        sort(vec.begin(), vec.end(), compareByMem);
    }
    else{
        return ;
    }

}


};


int main()
{
    tasklist x;
    x.save();
    x.display();
    x.sortit();
    x.display();



    return 0;
}
