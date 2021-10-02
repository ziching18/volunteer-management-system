#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include "queue.h"
using namespace std;

void modifyVolAcc(string volID);
void modifyEvent(string eventID);
void modifyEventList(string eventID);

void modifyVolAcc(string volID){
    string newName, newGender, newCont, newEmail, newLoca;
    string fileName = "volunteer/" + volID + ".txt";
    Queue v;

    cout << "Please input the new account details: " << endl;
    cout << "New name: ";
    cin.ignore();
    getline(cin, newName);

    cout << "New gender: ";
    cin >> newGender;

    cout << "New contact: ";
    cin >> newCont;

    cout << "New email: ";
    cin >> newEmail;

    cout << "New address: ";
    cin.ignore();
    getline(cin, newLoca);

    v.enqueue(newName);
    v.enqueue(newGender);
    v.enqueue(newCont);
    v.enqueue(newEmail);
    v.enqueue(newLoca);
    //v.displayQueue(); //debug

    v.outputQueue(fileName);
}

void modifyEvent(string eventID){
    string newName, newCate, newOName, newOCont, newDate,
           newTime, newLoca, newPCode, newDes, newMinAge, newReq;

    Queue q;
    string fileName = "event/" + eventID + ".txt";

    cout << "Please input the new event details: " << endl;
    cout << "New event name: ";
    cin.ignore();
    getline(cin, newName);
    //file << newName;

    cout << "New event catagory: ";
    cin >> newCate;

    cout << "New organization's name: ";
    cin.ignore();
    getline(cin, newOName);

    cout << "New organization's contact: ";
    cin >> newOCont;

    cout << "New event date: ";
    cin >> newDate;

    cout << "New event time: ";
    cin.ignore();
    getline(cin, newTime);

    cout << "New event location: ";
    cin.ignore();
    getline(cin, newLoca);

    cout << "New event location postcode: ";
    cin >> newPCode;

    cout << "New event description: ";
    cin.ignore();
    getline(cin, newDes);

    cout << "New volunteer minimum age: ";
    cin >> newMinAge;

    cout << "New volunteer requirement: ";
    cin.ignore();
    getline(cin, newReq);

    q.enqueue(newName);
    q.enqueue(newCate);
    q.enqueue(newOName);
    q.enqueue(newOCont);
    q.enqueue(newDate);
    q.enqueue(newTime);
    q.enqueue(newLoca);
    q.enqueue(newPCode);
    q.enqueue(newDes);
    q.enqueue(newMinAge);
    q.enqueue(newReq);
    //q.displayQueue();  //debug

    q.outputQueue(fileName);
}

void modifyEventList(string eventID, string newName){
    string fName = "eventName.txt";
    ifstream inFile(fName);
    ofstream outFile(fName);
    string name;
    vector<string> nameList;

    if(!inFile.is_open()){
        cout << "The file is not open" << endl;
    }else{
        while(getline(inFile, name)){
            nameList.push_back(name);
        }
    }

    int ID = stoi(eventID);
    nameList[ID - 1] = newName;

    for(int i = 0; i < nameList.size(); i++){
        outFile << nameList[i] << endl;
    }

    inFile.close();
    outFile.close();

}
