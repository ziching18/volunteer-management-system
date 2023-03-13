#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include "sort.h"
using namespace std;

// function declarations
vector<string> readDetail(string fname);
vector<vector<string>> searchList2D(char key);
vector<string> searchList(int criteria, char key);
int biSearch(string key, vector<string> searchVec);
void volSearchHeader();
void searchVol(string key,vector<vector<string>> volList, int criteria);
void displaySearchedVolBi(string key, int criteria);
void displaySearchedEventBi(string key, int criteria);
void searchEvent(string name, vector<vector<string>> event, int criteria);
void searchEventAge(int age, vector<vector<string>> event);
//void searchEventPcode(string pCode, vector<vector<string>> event);
void searchVolMenu();
void searchEventMenu();
void repeat2();
void repeat3();
void printHeader();
void volunteerMenu2();
void searchHeader();

vector<string> readDetail(string fname) // push each event detail into a vector
{
    string line;
    ifstream file(fname);
    vector<string> event;

    getline(file, line);
    stringstream ss(line);

    while(ss.good())
    {
        string sub;
        getline(ss, sub, ';');
        event.push_back(sub);
    };

    return event;
}

vector<vector<string>> searchList2D(char key)   // read file and push all event into a 2D vector
{
    string line, s_id, fname, parentName,file;
    vector<string> IDList;
    vector<vector<string>> searchID;

    if(key == 'e')
    {
        parentName = "Event/";
        file = "e_id.txt";
    }
    else if(key == 'v')
    {
        parentName = "Volunteer/";
        file = "v_id.txt";
    }

    ifstream readFile(file);

    if(!readFile.is_open())
    {
        cout << "Filed not opened!" << endl;
    }
    else
    {
        while(getline(readFile, s_id))
        {
            IDList.push_back(s_id);
        }

        for(int i = 0; i < IDList.size(); i++)
        {
            fname = parentName + IDList[i] + ".txt";
            //cout << str << " " << fname << endl; //debug
            searchID.push_back(readDetail(fname));
        }
    }
    //debug
    /*for (int i = 0; i < searchID.size(); i++) {
        for (int j = 0; j < searchID[i].size(); j++)
            cout << searchID[i][j] << " ";
        cout << endl;
    }*/
    return searchID;
}

vector<string> searchList(int criteria, char key)   // push criteria selected of all event into a vector
{
    vector<vector<string>> eList = searchList2D(key);
    vector<string> cList;

    for(int i = 0 ; i < eList.size(); i++)
    {
        cList.push_back(eList[i][criteria]);
    }

    //debug
    /*for (int i = 0; i < cList.size(); i++) {
        cout << cList[i] << " ";
        cout << endl;
    }*/
    return cList;
}

int biSearch(string key, vector<string> searchVec)  // binary search implementation
{
    vector<string> cList = searchVec;
    int n = cList.size();
    int l = 0;
    int r = n;

    while(l < r)
    {
        int mid = (l + r)/2;
        //cout <<"mid point: " << mid << endl; //debug
        int found = -1000;

        if(key == cList[mid])  //key found
        {
            found = 0;
        }

        //cout << "found: " << found << endl;
        if(found == 0)
        {
            return mid;
            break;
        }

        if(key > cList[mid])
        {
            l = mid++;
            //cout << "left ptr: " << l << endl; //debug
        }
        else
        {
            r = mid--;
            //cout << "right ptr: " << r << endl;  //debug
        }

        if(key > cList[n-1])   //if key > largest number direct return -1
        {
            return -1;
            break;
        }
    }
    return -1;
}


void volSearchHeader()
{
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\tVOLUNTEER DETAILS\n";
    cout << "\t\t\t\t\t\t\t--------------------------------\n\n\n";
    //cout << "\t\t" << setfill('_') << setw(55) << "_" << endl << endl;
    int colwidth = 8;
    cout << setfill('=') << setw(19*colwidth) << "=" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colwidth) << "ID" << setw(colwidth) << "Name" << setw(1.5*colwidth) << "" << setw(colwidth) << "Age" <<
            setw(colwidth) << "Gender" << setw(2*colwidth) << "Contact" << setw(4*colwidth) << "Email" <<
            setw(7*colwidth) << "Address" << endl;
    cout << setfill('=') << setw(19*colwidth) << "=" << endl;
    cout << setfill(' ') << fixed;

}

// vector<string> volIDList(string)
void searchVol(string key,vector<vector<string>> volList, int criteria)
{
    int n = volList.size();
    bool check = false;
    int counter = 1;

    for(int i=0; i < n; i++)
    {
        if(volList[i][criteria] == key)
        {
            viewVol(volList[i][0], false);
            //cout << endl;
            check = true;
        }
    }
    if(check == false)
    {
        cout << "\n\n\t\t\t\t\t\t\t     [Volunteer not found!]" << endl;
    }
}

void displaySearchedVolBi(string key, int criteria)
{
    int code = biSearch(key, searchList(criteria, 'v'));
    vector<vector<string>> vList = searchList2D('v');

    //cout << code << endl; //debug

    if(code == (-1))
    {
        cout << "\n\n\t\t\t\t\t\t\t     [Volunteer not found!]" << endl;
    }
    else
    {
        viewVol(vList[code][0], false);
    }
}

void displaySearchedEventBi(string key, int criteria)   // criteria used: name & date
{
    int code = biSearch(key, searchList(criteria, 'e'));
    vector<vector<string>> eList = searchList2D('e');

    //cout << code << endl; //debug
    /*for (int i = 0; i < eList.size(); i++) {
        cout << eList[i][criteria] << " ";
        cout << endl;
        }*/

    if(code == (-1))
    {
        cout << "\n\n\t\t\t      [Event not found!]" << endl;
    }
    else
    {
        viewEvent(eList[code][0], false, 1);
    }
}

void searchEvent(string key,vector<vector<string>> event, int criteria)
{
    int n = event.size();
    bool check = false;
    int counter = 1;
    for(int i=0; i < n; i++)
    {
        if(event[i][criteria] == key)
        {
            viewEvent(event[i][0], false, counter);
            cout << endl;
            check = true;
            break;
        }
    }
    if(check == false)
    {
        cout << "\n\n\t\t\t      [Event not found!]" << endl;
    }
}

// search by volunteer age requirement
void searchEventAge(int age, vector<vector<string>> event)
{
    int n = event.size();
    bool check = false;
    int counter = 1;
    for(int i = 0; i < n; i++)
    {
        int ageReq = stoi(event[i][12]);
        if(ageReq <= age)
        {
            viewEvent(event[i][0], false, counter);
            cout << endl;
            check = true;
            counter++;
        }
    }
    if(check == false)
    {
        cout << "\n\n\t\t\t      [Event not found!]" << endl;
    }
}

/*
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
}*/

void searchVolMenu()
{
    loop8:
    system("CLS");
    char choiceSV;
    string fname,lname, age, volID;
    string gender;

    cout << endl << endl << endl << setw(20) << setfill(' ') << " " << "==============================================" << endl;
    cout << setw(20) << setfill(' ') << " " << "|             Search Volunteer by            |" << endl;
    cout << setw(20) << setfill(' ') << " " << "==============================================\n\n\n";
    cout << "\t\t\t\t1. Volunteer ID" << endl;
    cout << "\t\t\t\t2. First Name"   << endl;
    cout << "\t\t\t\t3. Last Name"    << endl;
    cout << "\t\t\t\t4. Age"          << endl;
    cout << "\t\t\t\t5. Gender"       << endl;
    cout << "\t\t\t\t6. Return"  << endl;
    cout << "\n\n\t\t\tPLEASE CHOOSE (1|2|3|4|5|6): ";
    cin >> choiceSV;


    switch(choiceSV)
    {
        case '1':
            searchHeader();
            cout << "\n\n\t\tEnter Volunteer ID: " ;
            cin >> volID;
            while(volID.length() != 5)
            {
                cout << "\n\t\tInvalid format! \n\t\tPlease enter again: ";
                cin >> volID;
            }
            volSearchHeader();
            displaySearchedVolBi(volID, 0);
        break;
        case '2':
            searchHeader();
            cout << "\n\n\t\tEnter First Name: "; //1
            cin.ignore();
            getline(cin, fname);
            //cout << fname << endl;
            volSearchHeader();
            //displaySearchedVolBi(fname, 1);
            searchVol(fname, searchList2D('v'), 1);
        break;
        case '3':
            searchHeader();
            cout << "\n\n\t\tEnter Last Name: "; //2
            cin.ignore();
            getline(cin, lname);
            volSearchHeader();
            //displaySearchedVolBi(lname, 2);
            searchVol(lname, searchList2D('v'), 2);
        break;
        case '4':
            searchHeader();
            cout << "\n\n\t\tEnter Age: "; //3
            cin >> age;
            //cout << age << endl;
            volSearchHeader();
            //displaySearchedVolBi(age, 3);
            searchVol(age, searchList2D('v'), 3);
        break;
        case '5':
            searchHeader();
            cout << "\n\n\t\tEnter Gender (M|F|P): "; //4
            cin >> gender;
            while(gender != "F" && gender != "M" && gender != "P")
            {
                cout << "\n\t\tPlease Enter Gender (F|M|P): ";
                cin >> gender;
            }
            volSearchHeader();
            //displaySearchedVolBi(gender, 4);
            searchVol(gender, searchList2D('v'), 4);
        break;
        case '6':
            adminMenu2();
        break;
        default:
            goto loop8;

    }
    repeat2();
}

void searchHeader()
{
    system("CLS");
    printHeader();
    cout << endl << endl;
    cout << "\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|                  SEARCHING                  |\n";
    cout << "\t\t|_____________________________________________|\n";
}


void searchEventMenu()
{
    loop9:
    system("CLS");
    char choiceSE;
    int age;
    string name, date, postcode, id, volID;

    cout << endl << endl << endl << setw(20) << setfill(' ') << " " << "==============================================" << endl;
    cout << setw(20) << setfill(' ') << " " << "|               Search event by              |" << endl;
    cout << setw(20) << setfill(' ') << " " << "==============================================\n\n\n";
    cout << "\t\t\t\t1. Event ID"   << endl;
    cout << "\t\t\t\t2. Name"       << endl;
    cout << "\t\t\t\t3. Date"       << endl;
    cout << "\t\t\t\t4. Age"        << endl;
    cout << "\t\t\t\t5. Post code"  << endl;
    cout << "\t\t\t\t6. Return"  << endl;
    cout << "\n\n\t\t\tPLEASE CHOOSE (1|2|3|4|5|6): ";
    cin >> choiceSE;

    switch(choiceSE)
    {
        case '1':
            searchHeader();
            cout << "\n\n\t\tEnter event ID: " ;
            cin >> id;
            while(id.length() != 4)
            {
                cout << "\n\t\tInvalid format! \n\t\tPlease enter again: ";
                cin >> id;
            }
            displaySearchedEventBi(id, 0);
        break;
        case '2':
            searchHeader();
            cout << "\n\n\t\tEnter Event Name: "; //1
            cin.ignore();
            getline(cin, name);
            //displaySearchedEvent(name, 1);
            searchEvent(name, searchList2D('e'),1);
        break;
        case '3':
            searchHeader();
            cout << "\n\n\t\tEnter Event Date: "; //6
            cin >> date;
            searchEvent(date, searchList2D('e'), 6);
        break;
        case '4':
            searchHeader();
            cout << "\n\n\t\tEnter Your Age: "; //12
            cin >> age;
            searchEventAge(age, searchList2D('e'));
        break;
        case '5':
            searchHeader();
            cout << "\n\n\t\tEnter Postcode: "; //10
            cin >> postcode;
            while(postcode.length() != 5)
            {
                cout << "\n\t\tInvalid format! \n\t\tPlease enter again: ";
                cin >> postcode;
            }
            searchEvent(postcode, searchList2D('e'), 10);
        break;
        case '6':
            volunteerMenu2();
        break;
        default:
            goto loop9;
    }
    repeat3();
}

//reference: geeksforgeeks.org/binary-search-a-string/
