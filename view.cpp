#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
    //int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    vfile.open("volunteer.txt", ios::in);
    vidfile.open("volunteer-id.txt", ios::in);

    if (!vidfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {
        cout << "\n\t\t\tDISPLAYING ALL VOLUNTEERS\n" << endl;
        volHeader();
        while (vidfile >> id) {
            //cout << id;
            viewVol(id, false);
        }
    }

}

void viewVol(string id, bool lay)
{
    fstream vfile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    vfile.open("volunteer.txt", ios::in);

    //cout << "\n\t\t\tDISPLAYING ALL VOLUNTEERS\n" << endl;

    if (!vfile.is_open()) {                 // file not opened
        cout << "file not opened!" << endl;
    }
    else {                                  // file opened
        string vID, vfname, vlname, vage, vgender, vcontact, vemail, vlocation, vecontact;
        int colwidth = 8;
        //volHeader();
        while(vfile >> vID >> vfname >> vlname >> vage >> vgender >> vcontact >> vemail >> vlocation >> vecontact) {
            flag = false;
            counter += 1;
            if (vID == id) {
                if (layout == true) {
                    volHeader();
                }
                cout << setw(colwidth) << vID << setw(colwidth) << vfname << setw(1.5*colwidth) << vlname << setw(colwidth) << vage <<
                        setw(colwidth) << vgender << setw(2*colwidth) << vcontact << setw(3.5*colwidth) << vemail <<
                        setw(2*colwidth) << vlocation << setw(2.5*colwidth) << vecontact << endl;
                layout = false;
            }
        }
        vfile.close();
    }
}

void volHeader()
{
    int colwidth = 8;
    cout << setfill('*') << setw(16*colwidth) << "*" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colwidth) << "ID" << setw(colwidth) << "Name" << setw(1.5*colwidth) << "" << setw(colwidth) << "Age" <<
            setw(colwidth) << "Gender" << setw(2*colwidth) << "Contact" << setw(3.5*colwidth) << "Email" <<
            setw(2*colwidth) << "Location" << setw(2.5*colwidth) << "Emergency contact" << endl;
    cout << setfill('*') << setw(16*colwidth) << "*" << endl;
    cout << setfill(' ') << fixed;
}

void viewOrg(string id, bool lay)
{
    fstream ofile;
    string line;
    bool flag = true;
    bool layout = lay;
    int counter = 0;

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
    //displayVolAcc();
    displayOrgAcc();
    //viewVol("v00001", true);

    return 0;
}
