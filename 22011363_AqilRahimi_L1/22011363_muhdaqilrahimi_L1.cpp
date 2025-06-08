/*
Name : Muhammad Aqil Rahimi bin Mohamad Rasidi
Id : 22011363
*/

#include <iostream>
using namespace std;

struct Student{
    string name;
    int id;
    int contact;
    string email;
    
};

int main()
{
    Student student[5];
    
    for(int i = 0; i < 5; i++){
        cout<<"Enter name: ";
        cin>>student[i].name;
        
        cout<<"Enter id: ";
        cin>>student[i].id;
        
        cout<<"Enter contact: ";
        cin>>student[i].contact;
        
        cout<<"Enter email: ";
        cin>>student[i].email;
    }
    
    cout<<"Name \t ID \t Contact No \t Email\n";
    
    for(int i = 0; i < 5; i++){
        cout<<student[i].name<<"\t"<<student[i].id<<"\t"<<student[i].contact<<"\t"<<student[i].email<<"\n";
    }
    return 0;
}