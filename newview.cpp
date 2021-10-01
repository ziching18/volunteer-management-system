#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
//#include <filesystem>
using namespace std;

void viewVol(string, bool);
void displayVolAcc();
void volHeader();

void viewEvent(string, bool, int);
void displayEvents();
void eventHeader();


// view function

void displayVolAcc()
{
    fstream vfile, vidfile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;

    vidfile.open("volunteer-id.txt", ios::in);

    vector<string>ids;

    if (!vidfile.is_open()) {                 // file not opened
        cout << "File not opened!" << endl;
    }
    else {
        cout << "\n\t\t\t\t\tDISPLAYING ALL VOLUNTEERS\n" << endl;
        volHeader();
        while (getline(vidfile, id)) {
            ids.push_back(id);
        }
        for (int i=0; i<ids.size(); i++) {
            viewVol(ids[i], false);
        }
        cout << setfill('_') << setw(112) << "_" << endl;
    }
    vidfile.close();

}

void viewVol(string id, bool lay)
{
    fstream vfile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

    vfile.open("volunteer/" + id + ".txt", ios::in);

    if (!vfile.is_open()) {                 // file not opened
        cout << "File not opened!" << endl;
    }
    else {                                  // file opened
        string v_ID, v_fname, v_lname, v_age, v_gender, v_contact,
               v_email, v_address, v_emergencyName , v_emergencyRel, v_emergencyCon;
        int colwidth = 8;

        // get line from file, cut into substrings using delimiter ';'
        getline(vfile, line);
        vector<string> v;

        stringstream ss(line);

        while (ss.good()) {
            string sub;
            getline(ss, sub, ';');
            v.push_back(sub);
        }

        // assign substring to string variables
        v_ID = v[0];
        v_fname = v[1];
        v_lname = v[2];
        v_age = v[3];
        v_gender = v[4];
        v_contact = v[5];
        v_email = v[6];
        v_address = v[7];
        v_emergencyName = v[8];
        v_emergencyRel = v[9];
        v_emergencyCon = v[10];

        flag = false;
        counter += 1;
        if (v_ID == id) {
            if (layout == true) {
                volHeader();
            }
            cout << setw(colwidth) << v_ID << setw(colwidth) << v_fname << setw(1.5*colwidth) << v_lname << setw(colwidth) << v_age <<
                    setw(colwidth) << v_gender << setw(2*colwidth) << v_contact << setw(3.5*colwidth) << v_email <<
                    setw(2*colwidth) << v_address << endl;
            layout = false;
        }

        vfile.close();
    }
}

void volHeader()
{
    int colwidth = 8;
    cout << setfill('=') << setw(14*colwidth) << "=" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colwidth) << "ID" << setw(colwidth) << "Name" << setw(1.5*colwidth) << "" << setw(colwidth) << "Age" <<
            setw(colwidth) << "Gender" << setw(2*colwidth) << "Contact" << setw(3.5*colwidth) << "Email" <<
            setw(2*colwidth) << "Location" << endl;
    cout << setfill('=') << setw(14*colwidth) << "=" << endl;
    cout << setfill(' ') << fixed;

}

void displayEvents()
{
    fstream efile, eidfile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;

    eidfile.open("event-id.txt", ios::in);

    vector<string>ids;

    if (!eidfile.is_open()) {                 // file not opened
        cout << "File not opened!" << endl;
    }
    else {
        cout << "\n\n\t\t\t\t\tDISPLAYING ALL EVENTS\n" << endl;
        //eventHeader();
        while (getline(eidfile, id)) {
            ids.push_back(id);
        }
        for (int i=0; i<ids.size(); i++) {
            int n = i+1;
            viewEvent(ids[i], false, n);
        }
    }
    eidfile.close();
}

void viewEvent(string id, bool lay, int num)
{
    fstream efile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

    efile.open("event/" + id + ".txt", ios::in);

    if (!efile.is_open()) {                 // file not opened
        cout << "File not opened!" << endl;
    }
    else {        // file opened, get line from file, cut into substrings using delimiter ';'
        string e_ID, e_name, e_category, o_name, o_contact, e_date, e_time,
               e_location, e_postcode, e_description, volMinAge, volRequirement;
        int colwidth = 8;
        getline(efile, line);
        vector<string>e;

        stringstream ss(line);

        while (ss.good()) {
            string sub;
            getline(ss, sub, ';');
            e.push_back(sub);
        }

        // assign substring to string variables
        e_ID = e[0];
        e_name = e[1];
        e_category = e[2];
        o_name = e[3];
        o_contact = e[4];
        e_date = e[5];
        e_time = e[6];
        e_location = e[7];
        e_postcode = e[8];
        e_description = e[9];
        volMinAge = e[10];
        volRequirement = e[11];

        flag = false;
        counter += 1;
        if (e_ID == id) {
            cout << "\n\n\t\t" << left << setw(23) << setfill(' ') << num;
            cout << "\n\n\t\t" << left << setw(23) << setfill(' ') << "Event ID" << ":\t" << e_ID;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Category" << ":\t" << e_category;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Organiser Name" << ":\t" << o_name;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Organiser Contact" << ":\t" << o_contact;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Date" << ":\t" << e_date;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Time" << ":\t" << e_time;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Location" << ":\t" << e_location;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Postcode" << ":\t" << e_postcode;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Description" << ":\t" << e_description;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Volunteer Minimum Age" << ":\t" << volMinAge;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Volunteer Requirement" << ":\t" << volRequirement;
        }

        efile.close();
    }
}

void eventHeader()
{
    int colwidth = 8;
    cout << setfill('=') << setw(14*colwidth) << "=" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colwidth) << "ID" << setw(colwidth) << "Name" << setw(1.5*colwidth) << "Category" << setw(colwidth) << "Organiser" <<
            setw(colwidth) << "Contact" << setw(2*colwidth) << "Date" << setw(3.5*colwidth) << "Time" <<
            setw(2*colwidth) << "Location" << setw(2*colwidth) << "Postcode" <<
            setw(2*colwidth) << "Description" << setw(2*colwidth) << "Min Age" <<
            setw(2*colwidth) << "Requirements" << endl;
    cout << setfill('=') << setw(14*colwidth) << "=" << endl;
    cout << setfill(' ') << fixed;
}

/**
int main()
{
    //string a[2] = {"1", "2"};
    displayVolAcc();
    //displayOrgAcc();
    //viewVol("1", true);
    //viewOrg();
    displayEvents();

    return 0;
}
//**/
