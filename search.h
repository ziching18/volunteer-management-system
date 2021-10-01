#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include "Event.h"
using namespace std;

//function declaration
vector<string> readEvent(string fname);
vector<vector<string>> eventList();
void searchVolID(string searchID);
void searchEventName(string name, vector<vector<string>> event);
void searchEventDate(string date, vector<vector<string>> event);
void searchEventAge(int age, vector<vector<string>> event);
void searchEventPcode(string pCode, vector<vector<string>> event);
Event a;

vector<string> readEvent(string fname){
    string line;
    ifstream file(fname);
    vector<string> event;

    getline(file, line);
    stringstream ss(line);

    while(ss.good()){
        string sub;
        getline(ss, sub, ';');
        event.push_back(sub);
    };

    return event;
}

vector<vector<string>> eventList(){
    ifstream ENfile("eventName.txt");
    string line, name, fname;
    vector<string> eventNL;
    vector<vector<string>> eventlist;


    if(!ENfile.is_open()){
        cout << "The file is not open" << endl;
    }else{
        while(getline(ENfile, name)){
            eventNL.push_back(name);
        }

        int counter = 1;
        for(int i = 0; i < eventNL.size(); i++){
            string str = to_string(counter);
            fname = "event/" + str + ".txt";
            eventlist.push_back(readEvent(fname));
            counter++;
        }
    }


    //debug
    /*for (int i = 0; i < eventlist.size(); i++) {
        for (int j = 0; j < eventlist[i].size(); j++)
            cout << eventlist[i][j] << " ";
        cout << endl;
    }*/
    return eventlist;
}

void searchEvent(){
    int choice, age;
    string name, date, postcode;
    cout << "Search event by:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Date" << endl;
    cout << "3. Age" << endl;
    cout << "4. Location" << endl;
    cin >> choice;

    switch(choice){
    case 1:
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        searchEventName(name, eventList());
        break;
    case 2:
        cout << "Enter date: ";
        cin >> date;
        searchEventDate(date, eventList());
        break;
    case 3:
        cout << "Enter your age: ";
        cin >> age;
        searchEventAge(age, eventList());
        break;
    case 4:
        cout << "Enter postcode: " << endl;
        cin >> postcode;
        break;
    default:
        cout << "Invalid input" << endl;
    }
}

void searchVolID(string searchID){
    ifstream volIDfile ("volunteer-id.txt");
    string volID;
    vector <string> volIDList;
    bool check = true;

    if(!volIDfile.is_open()){
        cout << "The file is not open" << endl;
    }else{
        while(getline(volIDfile, volID)){
            volIDList.push_back(volID);
        }
    }

    for(int i = 0; i < volIDList.size(); i++){
        if( searchID == volIDList[i] ){
            cout << "The ID is valid" << endl;
        }else{
            check = false;
        }
    }
    if(check = false){
        cout << "event not found" << endl;
    }
}

void searchEventName(string name, vector<vector<string>> event){
    int n = event.size();
    bool check = false;
    for(int i = 0; i < n; i++){
        if( event[i][1] == name ){
            a.displayEventChoice(event[i][0]);
            cout << endl;
            check = true;
            break;
        }
    }
    if(check == false){
        cout << "event not found" << endl;
    }
}

void searchEventDate(string date, vector<vector<string>> event){
    int n = event.size();
    bool check = false;
    for(int i = 0; i < n; i++){
        if( event[i][5] == date ){
            a.displayEventChoice(event[i][0]);
            cout << endl;
            check = true;
            break;
        }
    }
    if(check == false){
        cout << "event not found" << endl;
    }

}

void searchEventAge(int age, vector<vector<string>> event){
    int n = event.size();
    bool check = false;
    for(int i = 0; i < n; i++){
        int ageReq = stoi(event[i][10]);
        if( ageReq >= age ){
            a.displayEventChoice(event[i][0]);
            cout << endl;
            check = true;
        }
    }
    if(check == false){
        cout << "event not found" << endl;
    }
}

void searchEventPcode(string postcode, vector<vector<string>> event){
    int n = event.size();
    bool check = false;
    for(int i = 0; i < n; i++){
        if( event[i][7] == postcode ){
            a.displayEventChoice(event[i][0]);
            cout << endl;
            check = true;
            break;
        }
    }
    if(check == false){
        cout << "event not found" << endl;
    }
}

