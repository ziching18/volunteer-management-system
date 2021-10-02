#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

#include <regex> //regex, regex_match

using namespace std;

string userID;

class Event
{
    private:
        int id;
        char answer;
        string e_ID;
        string e_name;
        string e_category;
        string o_name;
        string o_contact;
        string o_email;
        string e_date;
        string e_time;
        string e_duration;
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

            ifstream in("eventName.txt");   //input data from file
            vector<string>EName;

            while(getline(in, name, ';'))
            {            //input data from file into vector
                EName.push_back(name);
            };

            for(int i = 0; i < EName.size()-1; i++)
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
                o_email = e[5];
                e_date = e[6];
                e_time = e[7];
                e_duration = e[8];
                e_location = e[9];
                e_postcode = e[10];
                e_description = e[11];
                volMinAge = e[12];
                volRequirement = e[13];


                if (e_ID == eventChoice)
                {
                    system("CLS");
                    cout << "\n\n" << setw(15) << setfill(' ') << " " << setw(80) << setfill('=') << "=" << endl;
                    cout << setw(47) << setfill(' ') << " " << e_name;
                    cout << "\n" << setw(15) << setfill(' ') << " " << setw(80) << setfill('=') << "=" << endl;

                    cout << "\n\n\t\t" << left << setw(23) << setfill(' ') << "Event Category" << ":\t" << e_category;
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

        void selectEvent()
        {
            string choiceE;
            char responseE;
            char ansE;

            system("CLS");
            listEvent();
            cout << "\n\n\t\t\t\t\tPLEASE CHOOSE: ";
            cin >> choiceE;
            displayEventChoice(choiceE);

            cout << "\n\n" << setw(15) << setfill(' ') << " " << setw(80) << setfill('_') << "_" << endl;



            while(responseE != 'Y' && responseE != 'y' && responseE != 'n' && responseE != 'N')
            {
                cout << "\n\n\t\t\t\t  Want to register for this event? (y|n): ";
                cin >> responseE;
                cout << endl;

                if(responseE != 'Y' && responseE != 'y' && responseE != 'n' && responseE != 'N')
                {
                    cout << "\t\t\t\tInvalid Input!";
                }
                else if(responseE == 'Y' || responseE == 'y')
                {
                    cout << "\n\n\t\t\t-------------------------------------------------------------";
                    cout << "\n\n\t\t\t[Please enter your ID to confirm the registration of event]" << endl;
                    cout << "\n\t\t\tUser ID: ";
                    cin >> userID;

                    while(userID.length() != 5)
                    {
                        cout << "\n\t\t\t[userID needs to have 5 characters]" << endl;
                        cout << "\n\t\t\tPlease re-enter userID: ";
                        cin >> userID;
                    }

                    cout << "\n\n\t\t\tAre you sure this is the correct ID? (y|n): ";
                    cin >> ansE;

                    if(ansE == 'Y' || ansE == 'y')
                    {
                        ofstream UserFile;
                        UserFile.open("C:/Users/jingj/Documents/MMU/Degree/Degree Year2/Sem 3/Data Structure and Algorithm/Project/Combine/event/registered/" + e_ID + ".txt" , std::ios_base::app);

                        UserFile << userID << ";";

                        UserFile.close();

                        cout << "\n\n\t\t\t\t _____________________________________________\n";
                        cout << "\t\t\t\t|                                             |\n";
                        cout << "\t\t\t\t|           Registration Successful!          |\n";
                        cout << "\t\t\t\t|_____________________________________________|\n\n\n";
                    }
                    else
                    {
                        cout << "\n\n\t\t\t[Please register again thank you]" << endl;
                        selectEvent();
                    }
                }
                else
                {
                        //repeat();
                }
            }
        }

        string convertToString(char* a, int size)
        {
            int i;
            string s = "";
            for (i = 0; i < size; i++) {
                s = s + a[i];
            }
            return s;
        }

        void createID()
        {
            fstream idFile;
            idFile.open("e_id.txt");
            if(idFile.is_open()){
                idFile.seekg(-7,ios::end); //move 5 positions before EOF
                char previous[6];
                idFile.read(previous,5);
                previous[6]=0; //end with NULL character
                //convert char to int
                id = stoi(previous);
                id++;

                ofstream fout;
                fout.open("e_id.txt", ios::app);
                fout << setw(5) << setfill('0') << id << endl;
                fout.close();
            }
            idFile.seekg(-7,ios::end);
            char current[6];
            idFile.read(current,5);
            current[6]=0;
            e_ID = convertToString(current,5);
            idFile.close();
        }

        bool emailValidation(string& o_email)
        {
            const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
            return regex_match(o_email,pattern);
        }

        void createEvent()
        {

            cout << "\n\n\t" << setw(63) << setfill('*') << "*" << endl;
            cout << "\t\t\t  VOLUNTEER MANAGEMENT SYSTEM" << endl;
            cout << "\t" << setw(63) << setfill('*') << "*" << endl;

            cout << "\n\n" << setw(30) << setfill(' ') << " " << "Event Creating Page" << endl;
            cout << "\t\t______________________________________________" << endl << endl;

            cout << "\t\t _____________________________________________\n";
            cout << "\t\t|                                             |\n";
            cout << "\t\t|           Event Organiser Details           |\n";
            cout << "\t\t|_____________________________________________|\n";

            cout << "\n\n\t\tEnter Organiser Name: ";
            getline(cin, o_name);

            cout << "\n\t\tEnter Organiser Contact: ";
            getline(cin, o_contact);

            cout << "\n\t\tEnter Organiser Email: ";
            cin >> o_email;

            bool emailValid = emailValidation(o_email);
            while (emailValid == 0)
            {
                cout << "\n\t\t[Email does not exist]" << endl;
                cout << "\n\t\tPlease Re-Enter Email: ";
                cin >> o_email;
                emailValid = emailValidation(o_email);
            }

            cin.ignore();
            cout << "\n\n\t\t _____________________________________________\n";
            cout << "\t\t|                                             |\n";
            cout << "\t\t|                Event Details                |\n";
            cout << "\t\t|_____________________________________________|\n";

            cout << "\n\n" << setw(26) << setfill(' ') << " " << "--------------------------";
            cout << "\n" << setw(30) << setfill(' ') << " " << "Formal";
            cout << "\n" << setw(30) << setfill(' ') << " " << "Governance";
            cout << "\n" << setw(30) << setfill(' ') << " " << "Non-formal";
            cout << "\n" << setw(30) << setfill(' ') << " " << "Social Action";
            cout << "\n" << setw(30) << setfill(' ') << " " << "Project Based";
            cout << "\n" << setw(26) << setfill(' ') << " " << "--------------------------";
            cout << "\n\n\t\tEnter Event Category: ";
            getline(cin, e_category);

            cout << "\n\t\tEnter Event Name: ";
            getline(cin, e_name);

            cout << "\n\n" << setw(26) << setfill(' ') << " " << "--------------------------";
            cout << "\n" << setw(30) << setfill(' ') << " " << "Long-Term (?month)";
            cout << "\n" << setw(30) << setfill(' ') << " " << "Short-Term (?week)";
            cout << "\n" << setw(30) << setfill(' ') << " " << "One Day";
            cout << "\n" << setw(26) << setfill(' ') << " " << "--------------------------";
            cout << "\n\n\t\tEnter Event Duration: ";
            getline(cin, e_duration);

            cout << "\n\t\tEnter Event Date: ";
            cin >> e_date;

            cout << "\n\t\tEnter Event Time: ";
            cin >> e_time;

            cin.ignore();
            cout << "\n\t\tEnter Event Location: ";
            getline(cin, e_location);

            cout << "\n\t\tEnter Event Location Postcode: ";
            cin >> e_postcode;

            cin.ignore();
            cout << "\n\t\tEnter Event Description: ";
            getline(cin, e_description);

            cout << "\n\n\t\t _____________________________________________\n";
            cout << "\t\t|                                             |\n";
            cout << "\t\t|           Volunteer Requirements            |\n";
            cout << "\t\t|_____________________________________________|\n";

            cout << "\n\n\t\tEnter Minimum Volunteer Required Age: ";
            cin >> volMinAge;

            cin.ignore();
            cout << "\n\t\tEnter Volunteer Requirement: ";
            getline(cin, volRequirement);

            while(answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
            {
                cout << "\n\n\t\t______________________________________________" << endl;
                cout << "\n\t\tAll information had been key in correctly? (y|n): ";
                cin >> answer;

                if(answer == 'Y' || answer == 'y')
                {
                    createID();
                    /*ofstream eventName;
                    eventName.open("eventName.txt", ios::app);
                    eventName << e_name <<endl;
                    eventName.close();*/

                    ofstream UserFile;
                    UserFile.open("Event/" + e_ID + ".txt" , std::ios_base::app);

                    UserFile << e_ID << ";" << e_name << ";" << e_category << ";" << o_name << ";" << o_contact << ";" <<  o_email << ";" << e_date
                        << ";" << e_time << ";" << e_duration << ";" << e_location << ";" << e_postcode << ";" << e_description << ";"
                        << volMinAge << ";" << volRequirement;

                    cout << "\n\n\n\n" << setw(27) << setfill(' ') << " " << "***********************" << endl;
                    cout << setw(27) << setfill(' ') << " " << "*   EVENT CREATED!  *" << endl;
                    cout << setw(27) << setfill(' ') << " " << "***********************" << endl << endl << endl;

                    UserFile.close();
                }
                else if (answer == 'N' || answer == 'n')
                {
                    cout << "\n\n\t\tPlease fill in the information again. Thank you";
                    createEvent();
                }

            }



        }


};

int main()
{
    Event a;
    a.createID();
}
