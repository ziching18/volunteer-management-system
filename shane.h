#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

void modifyAcc(Account a, string newName, string newContact, string newEmail, string newLocation){
    a.name = newName;
    a.contact = newContact;
    a.email = newEmail;
    a.location = newLocation;
}

void modifyVolAcc(Volunteer a, string newName, string newGender, string newContact, string newEmail, string newLocation){
    a.name = newName;
    a.gender = newGender;
    a.contact = newContact;
    a.email = newEmail;
    a.location = newLocation;
}


void modifyOrgAcc(Organization a, string newName, string newContact, string newEmail, string newLocation){
    a.name = newName;
    a.contact = newContact;
    a.email = newEmail;
    a.location = newLocation;
}

//create a parent class call account maybe??

//a new class Event needed maybe???
void searchEvent(string name, Event arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if( arr[i].name == name ){
            displayEvent(arr[i].id);
            cout << endl;
        }else{
            cout << "Event not found!" << endl;
        }
    }
}

void searchEvent(string date, Event arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if( arr[i].date == date ){
            displayEvent(arr[i].id);
            cout << endl;
        }else{
            cout << "Event not found!" << endl;
        }
    }
}

void searchEvent(int low, int high, Event arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        int Lage = stoi(arr[i].lowAge);
        int Hage = stoi(arr[i].highAge);

        if( low >= Lage && high <= Hage ){
            displayEvent(arr[i].id);
            cout << endl;
        }else{
            cout << "Event not found!" << endl;
        }
    }
}

void searchEvent(string location, Event arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if( arr[i].location == location ){
            displayEvent(arr[i].id);
            cout << endl;
        }else{
            cout << "Event not found!" << endl;
        }
    }
}

