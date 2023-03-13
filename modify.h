#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iomanip>
#include "queue.h"
using namespace std;

// function declarations
string checkInputID(string inputID, char key);
void modifyVolAcc(string volID);
void modifyEvent(string eventID);
void modifyEventList(string eventID, string newName);
void repeat2();
void repeat3();
void printHeader();

string validID;

string checkInputID(string inputID, char key){
    string file, ids, input;
    vector<string> IDList;
    bool check = 0;

    if(key == 'e')
    {
        file = "e_id.txt";
    }
    else if(key == 'v')
    {
        file = "v_id.txt";
    }

    ifstream read(file);

    if(!read.is_open())
    {
        cout << "Filed not opened!" << endl;
    }
    else
    {
        while(getline(read, ids))
        {
            IDList.push_back(ids);
        }
    }

    //cout << check << endl; //debug
    for(int i = 0; i < IDList.size() && check == 0; i++)
    {
        //cout << IDList[i] << endl;   //debug
        if(inputID == IDList[i])
        {
            check = 1;
            cout << "\n\t\tValid ID" <<endl;
            validID = inputID;
            break;
        }
    }

    if(check == 0)
    {
        cout << "\n\t\t[Invalid ID!]" << endl;
        cout << "\t\tPlease input again: ";
        cin >> inputID;  //if ID invalid request user to input again
        //cout <<"input: "<< inputID << endl;
        checkInputID(inputID, key);  //call function check the ID again
    }
    return validID;
}

// modify volunteer details - username + password cannot be modified
void modifyVolAcc(string inputID)
{
    string volID = checkInputID(inputID, 'v');
    string newfName, newlName, newAge, newGender, newCont, newEmail, newLoca,
           newEmerName, newEmerRel, newEmerCont;
    string fileName = "Volunteer/" + volID + ".txt";
    Queue v;

    system("cls");

    printHeader();
    cout << "\n\n\t\tVolunteer ID: " << volID << endl << endl;
    cout << "\n\n" << setw(22) << setfill(' ') << " " << "Please fill in your details below" << endl;
    cout << "\t\t______________________________________________" << endl << endl;

    cin.ignore();
    cout << "\n\t\tEnter First Name: ";
    getline(cin, newfName);

    cout << "\n\t\tEnter Last Name: ";
    getline(cin, newlName);

    cout << "\n\t\tEnter Age: ";
    cin >> newAge;
    if (inputNum(newAge))
    {
        if (stoi(newAge) < 18)
        {
            cout << "\n\t\t[You must be at least 18 years old]" << endl;

                if (repeat() == true)
                {
                    welcomePage();
                }
                else
                {
                    exit(0);
                }
        }
    }
    else
    {
        while (inputNum(newAge) == 0)
        {
            cout << "\n\t\t[Please ensure that your input is integer]" << endl;
            cout << "\n\t\tPlease Re-Enter Your Age:";
            cin >> newAge;
        }
    }

    cout << "\n\n" << setw(26) << setfill(' ') << " " << "--------------------------";
    cout << "\n" << setw(28) << setfill(' ') << " " << "F - Female";
    cout << "\n" << setw(28) << setfill(' ') << " " << "M - Male";
    cout << "\n" << setw(28) << setfill(' ') << " " << "P - Prefer Not to Say";
    cout << "\n" << setw(26) << setfill(' ') << " " << "--------------------------";
    cout << "\n\n\t\tEnter Gender (F|M|P) : ";
    cin >> newGender;
    while(newGender != "F" && newGender != "M" && newGender != "P")
    {
        cout << "\n\t\tPlease Enter Gender (F|M|P): ";
        cin >> newGender;
    }

    cout << "\n\t\tEnter Contact No. (0123456789): ";
    cin >> newCont;
    while (inputNum(newCont) == 0)
    {
        cout << "\n\t\t[Invalid Input.Please ensure that your input is numbers]" << endl;
        cout << "\n\t\tPlease Re-Enter Your Contact No.(0123456789):";
        cin >> newCont;
    }

    cout << "\n\t\tEnter Email: ";
    cin >> newEmail;
    bool emailValid = emailValidation(newEmail);
    while (emailValid == 0)
    {
        cout << "\n\t\t[Email does not exist]" << endl;
        cout << "\n\t\tPlease Re-Enter Email: ";
        cin >> newEmail;
        emailValid = emailValidation(newEmail);
    }

    cin.ignore();
    cout << "\n\t\tEnter Full Address: ";
    getline(cin, newLoca);

    cout << "\n\n\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|           Emergency Contact Info            |\n";
    cout << "\t\t|_____________________________________________|";

    cout << "\n\n\n\t\tEnter Emergency Contact Name: ";
    getline(cin, newEmerName);

    cout << "\n\t\tEnter Emergency Contact Relationship: ";
    getline(cin, newEmerRel);

    cout << "\n\t\tEnter Emergency Contact No. (0123456789): ";
    cin >> newEmerCont;
    while (inputNum(newEmerCont) == 0)
    {
        cout << "\n\t\t[Invalid Input.Please ensure that your input is numbers]" << endl;
        cout << "\n\t\tPlease Re-Enter Your Contact No. (0123456789):";
        cin >> newEmerCont;
    }

    v.enqueue(volID);
    v.enqueue(newfName);
    v.enqueue(newlName);
    v.enqueue(newAge);
    v.enqueue(newGender);
    v.enqueue(newCont);
    v.enqueue(newEmail);
    v.enqueue(newLoca);
    v.enqueue(newEmerName);
    v.enqueue(newEmerRel);
    v.enqueue(newEmerCont);
    //v.displayQueue(); //debug

    v.outputQueue(fileName);

    cout << "\n\n\n\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|               Success Edited!               |\n";
    cout << "\t\t|_____________________________________________|\n";

    repeat3();
}

// modify event details
void modifyEvent(string inputID)
{
    string eventID = checkInputID(inputID, 'e');
    string newName, newCate, newOName, newOCont, newDate, newTime, newOEmail,
           newDuration, newLoca, newPCode, newDes, newMinAge, newReq;

    Queue e;
    string fileName = "Event/" + eventID + ".txt";
    //cout << fileName << endl; //debug

    system("cls");
    printHeader();
    cout << "\n\n\t\tEvent ID: " << eventID << endl << endl << endl;
    cout << "\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|           Event Organiser Details           |\n";
    cout << "\t\t|_____________________________________________|\n";

    cin.ignore();
    cout << "\n\n\t\tEnter Organiser Name: ";
    getline(cin, newOName);

    cout << "\n\t\tEnter Organiser Contact (0123456789): ";
    cin >> newOCont;

    while (inputNum(newOCont) == 0)
    {
        cout << "\n\t\t[Invalid Input.Please ensure that your input is numbers]" << endl;
        cout << "\n\t\tPlease Re-Enter Organiser Contact No.(0123456789):";
        cin >> newOCont;
    }

    cout << "\n\t\tEnter Organiser Email: ";
    cin >> newOEmail;

    bool emailValid = emailValidation(newOEmail);
    while (emailValid == 0)
    {
        cout << "\n\t\t[Email does not exist]" << endl;
        cout << "\n\t\tPlease Re-Enter Email: ";
        cin >> newOEmail;
        emailValid = emailValidation(newOEmail);
    }

    cin.ignore();
    cout << "\n\n\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|                Event Details                |\n";
    cout << "\t\t|_____________________________________________|\n";

    cout << "\n\n" << setw(26) << setfill(' ') << " " << "--------------------------";
    cout << "\n" << setw(30) << setfill(' ') << " " << "Formal";
    cout << "\n" << setw(30) << setfill(' ') << " " << "Governance";
    cout << "\n" << setw(30) << setfill(' ') << " " << "Non-Formal";
    cout << "\n" << setw(30) << setfill(' ') << " " << "Social Action";
    cout << "\n" << setw(30) << setfill(' ') << " " << "Project Based";
    cout << "\n" << setw(26) << setfill(' ') << " " << "--------------------------";
    cout << "\n\n\t\tEnter Event Category (Formal): ";
    getline(cin, newCate);

    cout << "\n\t\tEnter Event Name: ";
    getline(cin, newName);

    cout << "\n\n" << setw(26) << setfill(' ') << " " << "--------------------------";
    cout << "\n" << setw(30) << setfill(' ') << " " << "Long-Term (? month)";
    cout << "\n" << setw(30) << setfill(' ') << " " << "Short-Term (? week)";
    cout << "\n" << setw(30) << setfill(' ') << " " << "One Day";
    cout << "\n" << setw(26) << setfill(' ') << " " << "--------------------------";
    cout << "\n\n\t\tEnter Event Duration (One Day): ";
    getline(cin, newDuration);

    cout << "\n\t\tEnter Event Date (YYYYMMDD): ";
    getline(cin, newDate);

    cout << "\n\t\tEnter Event Time (24 Hour Format, 1300-1500): ";
    getline(cin, newTime);

    cout << "\n\t\tEnter Event Location: ";
    getline(cin, newLoca);

    cout << "\n\t\tEnter Event Location Postcode: ";
    cin >> newPCode;
    while (inputNum(newPCode) == 0 || newPCode.length() != 5)
    {
        cout << "\n\t\t[Invalid Input.Please ensure that your enter valid postcode]" << endl;
        cout << "\n\t\tPlease Re-Enter Event Location Postcode: ";
        cin >> newPCode;
    }
    cin.ignore();

    cout << "\n\t\tEnter Event Description: ";
    getline(cin, newDes);

    cout << "\n\n\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|           Volunteer Requirements            |\n";
    cout << "\t\t|_____________________________________________|\n";

    cout << "\n\n\t\tEnter Minimum Volunteer Age: ";
    cin >> newMinAge;

    if (inputNum(newMinAge))
    {
        while(stoi(newMinAge) < 18)
        {
            cout << "\n\t\t[Invalid requirement - Volunteer must be at least 18 years old]" << endl;
            cout << "\n\t\tPlease Re-Enter Minimum Volunteer Age: ";
            cin >> newMinAge;
        }
    }
    else
    {
        while(inputNum(newMinAge) == 0)
        {
            cout << "\n\t\t[Please ensure that your input is integer]" << endl;
            cout << "\n\t\tPlease Re-Enter Your Age: ";
            cin >> newMinAge;
        }
        while(stoi(newMinAge) < 18)
        {
            cout << "\n\t\t[Invalid requirements - Volunteer must be at least 18 years old]" << endl;
            cout << "\n\t\tPlease Re-Enter Minimum Volunteer Age: ";
            cin >> newMinAge;
        }
    }

    cin.ignore();
    cout << "\n\t\tEnter Volunteer Requirement: ";
    getline(cin, newReq);

    //repeat2();

    e.enqueue(eventID);
    e.enqueue(newName);
    e.enqueue(newCate);
    e.enqueue(newOName);
    e.enqueue(newOCont);
    e.enqueue(newOEmail);
    e.enqueue(newDate);
    e.enqueue(newTime);
    e.enqueue(newDuration);
    e.enqueue(newLoca);
    e.enqueue(newPCode);
    e.enqueue(newDes);
    e.enqueue(newMinAge);
    e.enqueue(newReq);
    //e.displayQueue();  //debug

    e.outputQueue(fileName);
    modifyEventList(eventID, newName);

    cout << "\n\n\n\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|               Success Edited!               |\n";
    cout << "\t\t|_____________________________________________|\n";

    repeat2();
}

// modify list of events
void modifyEventList(string eventID, string newName)
{
    string fName = "eventName.txt";
    ifstream inFile(fName);
    string name;
    vector<string> nameList;

    if(!inFile.is_open())
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        while(getline(inFile, name))
        {
            nameList.push_back(name);
            //cout << name << endl; //debug
        }
    }
    inFile.close();

    int ID = stoi(eventID);
    nameList[ID - 1] = newName;

    ofstream outFile(fName);
    for(int i = 0; i < nameList.size(); i++)
    {
        //cout << nameList[i] << endl; //debug
        outFile << nameList[i] << endl;
    }
    outFile.close();
}
