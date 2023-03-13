#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
//#include <filesystem>
using namespace std;

// function declarations
void repeat2();
void repeat3();
void viewVolProfile(string);
void viewVol(string, bool);
void displayVolAcc();
void volHeader();
void viewEvent(string, bool, int);
void displayEvents();
void eventHeader();


// display user profile
void viewVolProfile(string id)
{
    fstream vfile;
    string line;
    string vid = id;

    vfile.open("volunteer/" + vid + ".txt", ios::in);

    if(!vfile.is_open())
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        string v_id, v_fname, v_lname, v_age, v_gender, v_contact,
               v_email, v_address, v_emergencyName , v_emergencyRel, v_emergencyCon;
        getline(vfile, line);
        vector<string> v;

        stringstream ss(line);

        while (ss.good())
        {
            string sub;
            getline(ss, sub, ';');
            v.push_back(sub);
        }

        v_id = v[0];
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

        cout << "\n\n\n\t\t\t\t       MY PROFILE" << endl;
        cout << "\t\t" << setfill('_') << setw(55) << "_" << endl;
        cout << "\n\n\t\t" << left << setw(23) << setfill(' ') << "ID" << ":\t" << v_id;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Name" << ":\t" << v_fname << " " << v_lname;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Age" << ":\t" << v_age;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Gender" << ":\t" << v_gender;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Contact number" << ":\t" << v_contact;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Email" << ":\t" << v_email;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Address" << ":\t" << v_address;
        cout << "\n\n\n\t\tEmergency Contact \n";
        cout << "\t\t" << setfill('-') << setw(17) << "-";
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Name" << ":\t" << v_emergencyName;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Relationship" << ":\t" << v_emergencyRel;
        cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Number" << ":\t" << v_emergencyCon;
        cout << endl << endl;
    }
    repeat3();
}

// show volunteer details
void viewVol(string id, bool lay)
{
    fstream vfile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

    vfile.open("volunteer/" + id + ".txt", ios::in);

    if (!vfile.is_open())   // file not opened
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        string v_ID, v_fname, v_lname, v_age, v_gender, v_contact,
               v_email, v_address, v_emergencyName , v_emergencyRel, v_emergencyCon;
        int colwidth = 8;

        getline(vfile, line);
        vector<string> v;

        stringstream ss(line);

        while (ss.good())
        {
            string sub;
            getline(ss, sub, ';');  // input stream converted into substrings with ; as delimiter
            v.push_back(sub);       // substrings pushed into vector
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
        counter += 1;   // loop through file
        if (v_ID == id) // id matches
        {
            if (layout == true) {
                volHeader();
            }
            cout << setw(colwidth) << v_ID << setw(colwidth) << v_fname << setw(1.5*colwidth) << v_lname << setw(colwidth) << v_age <<
                    setw(colwidth) << v_gender << setw(2*colwidth) << v_contact << setw(4*colwidth) << v_email <<
                    setw(7*colwidth) << v_address << endl;
            layout = false;
        }

        vfile.close();
    }

}

void volHeader()
{
    cout << "\n\n\n\t\t\t\t\t\t          DISPLAYING ALL VOLUNTEERS          \n";
    cout << "\t\t\t\t\t\t_____________________________________________\n\n\n";

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

// display all events by calling viewEvent()
void displayEvents()
{
    fstream efile, eidfile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;

    eidfile.open("e_id.txt", ios::in);

    vector<string>ids;

    if (!eidfile.is_open()) // file not opened
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        cout << "\n\n\t\t\t\tDISPLAYING ALL EVENTS" << endl;
        cout << "\t\t" << setfill('_') << setw(55) << "_" << endl;
        //eventHeader();
        while (getline(eidfile, id))
        {
            ids.push_back(id);      // get all event ids and push into vector
        }
        for (int i=0; i<ids.size(); i++)
        {
            int n = i+1;
            viewEvent(ids[i], false, n);    // display event using event id
        }
        cout << "\n\n\n\t\t" << setfill('_') << setw(55) << "_" << endl;
    }
    eidfile.close();
    repeat2();
}

// display event details
void viewEvent(string id, bool lay, int num)
{
    fstream efile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

    efile.open("event/" + id + ".txt", ios::in);

    if (!efile.is_open())   // file not opened
    {
        cout << "File not opened!" << endl;
    }
    else
    {
        string e_ID, e_name, e_category, o_name, o_contact, e_date, e_time, o_email, e_duration,
               e_location, e_postcode, e_description, volMinAge, volRequirement;
        int colwidth = 8;
        getline(efile, line);
        vector<string>e;

        stringstream ss(line);

        while (ss.good()) {
            string sub;
            getline(ss, sub, ';');  // input stream converted into substrings with ; as delimiter
            e.push_back(sub);       // substrings pushed into vector
        }

        // assign substring to string variables
        e_ID = e[0];
        e_name = e[1];
        e_category = e[2];
        o_name = e[3];
        o_contact = e[4];
        o_email = e[5];
        e_date = e[6];
        e_time = e[7];
        e_duration = e[8];
        e_location = e[9];
        e_postcode = e[10];
        e_description = e[11];
        volMinAge = e[12];
        volRequirement = e[13];

        flag = false;
        counter += 1;
        if (e_ID == id)
        {
            cout << "\n\n\t\t" << left << setw(23) << setfill(' ') << num;
            cout << "\n\n\t\t" << left << setw(23) << setfill(' ') << "Event ID" << ":\t" << e_ID;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Name" << ":\t" << e_name;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Category" << ":\t" << e_category;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Organiser Name" << ":\t" << o_name;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Organiser Contact" << ":\t" << o_contact;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Organiser Email" << ":\t" << o_email;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Date" << ":\t" << e_date;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Time" << ":\t" << e_time;
            cout << "\n\t\t" << left << setw(23) << setfill(' ') << "Event Duration" << ":\t" << e_duration;
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
