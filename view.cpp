#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
//#include <filesystem>
using namespace std;

// view function
void viewAll()
{
    fstream vfile;
    string line;
    bool flag = true;
    bool layout = true;
    int counter = 0;

    //vfile.open("volunteer/v00001.txt", ios::in);
    vfile.open("volunteer.txt", ios::in);

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

void view()
{

}

int main()
{
    viewAll();

    return 0;
}
