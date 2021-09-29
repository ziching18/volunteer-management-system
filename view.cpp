#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
//#include <filesystem>
using namespace std;

void viewVol(string id, bool lay);
void viewOrg(string id, bool lay);
void displayVolAcc();
void displayOrgAcc();
void volHeader();
void orgHeader();


// view function

/**
void viewVolProfile(Vol a)
{
    string id, fname, lname, age, gender, contact, email, address, emergencyName, emergencyRel, emergencyCon;
    id = a.id;
    fname = a.v_fname;
    lname = a.v_lname;
    age = a.v_age;
    gender = a.v_gender;
    contact = a.v_contact;
    email = a.v_email;
    address = a.v_address;
    emergencyName = a.v_emergencyName;
    emergencyRel = a.v_emergencyRel;
    emergencyCon = a.v_emergencyCon;


    cout << "\n\t\t\t\tYOUR PROFILE" << endl;
    cout << "\t\tID" << endl;
    cout << "\t\t" << id << endl;
    cout << "\t\tNAME" << endl;
    cout << "\t\t" << fname << " " << lname << endl;
    cout << "\t\AGE" << endl;
    cout << "\t\t" << age << endl;
    cout << "\t\GENDER" << endl;
    cout << "\t\t" << gender << endl;
    cout << "\t\CONTACT NUMBER" << endl;
    cout << "\t\t" << contact << endl;
    cout << "\t\EMAIL" << endl;
    cout << "\t\t" << email << endl;
    cout << "\t\LOCATION" << endl;
    cout << "\t\t" << address << endl;
    cout << "\t\EMERGENCY CONTACT NAME" << endl;
    cout << "\t\t" << emergencyName << endl;
    cout << "\t\EMERGENCY CONTACT RELATIVE" << endl;
    cout << "\t\t" << emergencyRel << endl;
    cout << "\t\EMERGENCY CONTACT" << endl;
    cout << "\t\t" << emergencyCon << endl;
}
**/
/**
void displayVolAcc()
{
    fstream vfile;
    string line;
    bool flag = true;
    bool layout = true;
    int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    vfile.open("volunteer.txt", ios::in);

    cout << "\n\t\t\tDISPLAYING ALL VOLUNTEERS\n" << endl;

    if (!vfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {                                  // file opened
        string vID, vfname, vlname, vage, vgender, vcontact, vemail, vlocation, vecontact;
        int colwidth = 8;
        while(vfile >> vID >> vfname >> vlname >> vage >> vgender >> vcontact >> vemail >> vlocation >> vecontact) {
            flag = false;
            counter += 1;
            if (layout == true) {
            cout << setfill('*') << setw(16*colwidth) << "*" << endl;
            cout << setfill(' ') << fixed;
            cout << setw(colwidth) << "ID" << setw(colwidth) << "Name" << setw(1.5*colwidth) << "" << setw(colwidth) << "Age" <<
                    setw(colwidth) << "Gender" << setw(2*colwidth) << "Contact" << setw(3.5*colwidth) << "Email" <<
                    setw(2*colwidth) << "Location" << setw(2.5*colwidth) << "Emergency contact" << endl;
            cout << setfill('*') << setw(16*colwidth) << "*" << endl;
            cout << setfill(' ') << fixed;
            }
            cout << setw(colwidth) << vID << setw(colwidth) << vfname << setw(1.5*colwidth) << vlname << setw(colwidth) << vage <<
                    setw(colwidth) << vgender << setw(2*colwidth) << vcontact << setw(3.5*colwidth) << vemail <<
                    setw(2*colwidth) << vlocation << setw(2.5*colwidth) << vecontact << endl;
            layout = false;
        }
        vfile.close();
    }

}
**/

void displayVolAcc()
{
    fstream vfile, vidfile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    //vfile.open("volunteer.txt", ios::in);
    vidfile.open("volunteer-id.txt", ios::in);
    //string a[2] = {"v00001", "v00002"};
    vector<string>ids;

    if (!vidfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {
        cout << "\n\t\t\tDISPLAYING ALL VOLUNTEERS\n" << endl;
        volHeader();
        while (getline(vidfile, id)) {
            //cout << id;
            ids.push_back(id);
        }
        for (int i=0; i<ids.size(); i++) {
            viewVol(ids[i], false);
            //cout << i;
        }
    }

}

/**
void viewVol(string id, bool lay)
{
    fstream vfile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    //vfile.open("volunteer.txt", ios::in);
    //cout << id << endl;
    vfile.open("volunteer/" + id + ".txt", ios::in);

    //cout << "\n\t\t\tDISPLAYING ALL VOLUNTEERS\n" << endl;

    if (!vfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {                                  // file opened
        string v_ID, v_fname, v_lname, v_age, v_gender, v_contact, v_email, v_address, v_emergencyName , v_emergencyRel, v_emergencyCon, stuff;
        int colwidth = 8;
        //volHeader();
        //vfile.ignore(0,';');
        while(vfile >> v_ID >> v_fname >> v_lname >> v_age >> v_gender >> v_contact
              >> v_email >> v_address >> v_emergencyName >> v_emergencyRel >> v_emergencyCon) {
            vfile.ignore(0,';');
            vfile.get();
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
        }
        vfile.close();
    }
}
**/

void viewVol(string id, bool lay)
{
    fstream vfile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    //vfile.open("volunteer.txt", ios::in);
    //cout << id << endl;
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
    cout << setfill('*') << setw(14*colwidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colwidth) << "ID" << setw(colwidth) << "Name" << setw(1.5*colwidth) << "" << setw(colwidth) << "Age" <<
            setw(colwidth) << "Gender" << setw(2*colwidth) << "Contact" << setw(3.5*colwidth) << "Email" <<
            setw(2*colwidth) << "Location" << endl;
    cout << setfill('*') << setw(14*colwidth) << "*" << endl;
    cout << setfill(' ') << fixed;
}

void viewOrg(string id, bool lay)
{
    fstream ofile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;
    string filename;

    //filename = id + ".txt";
    //cout << filename;

    //vfile.open("volunteer/v00001.txt", ios::in);
    ofile.open("organiser.txt", ios::in);

    //cout << "\n\t\t\tDISPLAYING ALL ORGANISERS\n" << endl;

    if (!ofile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {                                  // file opened
        string oid, oname, ocontact, oemail, osector, odescription1, odescription2;
        int colwidth = 8;
        while(ofile >> oid >> oname >> ocontact >> oemail >> osector >> odescription1) {
            //ofile.ignore();
            getline(ofile, odescription2);
            flag = false;
            counter += 1;
            if (oid == id) {
                if (layout == true) {
                    orgHeader();
                }
                cout << setw(colwidth) << oid << setw(colwidth) << oname << setw(colwidth*2) << ocontact <<
                        setw(3*colwidth) << oemail <<
                        setw(2*colwidth) << osector << setw(2*colwidth) << odescription1 << odescription2 << endl;
                layout = false;
            }
        }
        ofile.close();
    }
}

void displayOrgAcc()
{
    fstream ofile, oidfile;
    string line, id;
    bool flag = true;
    bool layout = true;
    int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    ofile.open("organiser.txt", ios::in);
    oidfile.open("organiser-id.txt", ios::in);

    if (!oidfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {                                  // file opened
        cout << "\n\t\t\tDISPLAYING ALL ORGANISERS\n" << endl;
        orgHeader();
        while (oidfile >> id) {
            viewOrg(id, false);
        }
    }

}

void orgHeader()
{
    int colwidth = 8;
    cout << setfill('*') << setw(16*colwidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colwidth) << "ID" << setw(colwidth) << "Name" << setw(colwidth*2) << "Contact" <<
            setw(3*colwidth) << "Email" <<
            setw(2*colwidth) << "Sector" << setw(2.5*colwidth) << "Description" << endl;
    cout << setfill('*') << setw(16*colwidth) << "*" << endl;
    cout << setfill(' ') << fixed;
}


int main()
{
    //string a[2] = {"1", "2"};
    displayVolAcc();
    //displayOrgAcc();
    //viewVol("1", true);
    //viewOrg();

    return 0;
}
