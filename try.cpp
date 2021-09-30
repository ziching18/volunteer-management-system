#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Event
{
    private:
        string e_ID;
        string e_name;
        string e_category;
        string o_name;
        string o_contact;
        string e_date;
        string e_time;
        string e_location;
        string e_postcode;
        string e_description;
        string volMinAge;
        string volRequirement;

    public:

        void listEvent()
        {
            string name;
            int counter =1;

            cout << "\n\n";
            cout << setw(20) << setfill(' ') << " " << setw(61) << setfill('=') << "=" << endl;
            cout << setw(20) << setfill(' ') << " " << "|                 List of Volunteer Programme               | " << endl;
            cout << setw(20) << setfill(' ') << " " << setw(61) << setfill('=') << "=" << endl;

            ifstream in("eventName.dat");   //input data from binary file
            vector<string>EName;

            while(getline(in, name))
            {            //input data from file into vector
                EName.push_back(name);
            };

            for(int i = 0; i < EName.size(); i++)
            {      //display item in vector
                cout << setw(20) << setfill(' ') << " " << "| " << counter <<"." ;
                cout << left << setw(56) << EName[i] << "|\n";
                counter++;
            }
            cout << setw(20) << setfill(' ') << " " << setw(61) << setfill('-') << "-" << endl;
            cout << endl;
        }



        void displayEventChoice(string eventChoice)
        {
            fstream efile;
            string line;

            efile.open("event/" + eventChoice + ".txt", ios::in);

            if (!efile.is_open())
            {                 // file not opened
                selectEvent();
            }

            else
            {        // file opened, get line from file, cut into substrings using delimiter ';'
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


                if (e_ID == eventChoice)
                {
                    system("CLS");
                    cout << "\n\n" << setw(15) << setfill(' ') << " " << setw(80) << setfill('=') << "=" << endl;
                    cout << setw(47) << setfill(' ') << " " << e_name;
                    cout << "\n" << setw(15) << setfill(' ') << " " << setw(80) << setfill('=') << "=" << endl;

                    cout << "\n\n\t\t" << left << setw(23) << setfill(' ') << "Event Category" << ":\t" << e_category;
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




        void selectEvent()
        {
            string choiceE;
            char responseE;

            system("CLS");
            listEvent();
            cout << "\n\n\t\t\t\t\tPLEASE CHOOSE: ";
            cin >> choiceE;
            displayEventChoice(choiceE);

            cout << "\n\n" << setw(15) << setfill(' ') << " " << setw(80) << setfill('_') << "_" << endl;



            while(responseE != 'Y' && responseE != 'y' && responseE != 'n' && responseE != 'N')
            {
                cout << "\n\n\t\t\t\tWant to register for this event?(y|n) :";
                cin >> responseE;
                cout << endl;

                if(responseE != 'Y' && responseE != 'y' && responseE != 'n' && responseE != 'N')
                {
                    cout << "\t\t\t\tInvalid Input!";
                }
                else
                {
                    if(responseE == 'Y' && responseE == 'y')
                    {
                        //append id into event file
                    }
                    else
                    {
                        repeat();
                    }

                }

            }




        }

        };



int main()
{
    Event A;
    A.selectEvent();
}
