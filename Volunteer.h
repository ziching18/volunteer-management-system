#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //used to create,write and read files
#include <conio.h> //used to call getch()
#include <regex> //regex, regex_match
//#include "function.h"

using namespace std;

void welcomePage();
bool repeat();
string convertToString(char* a, int size);
bool inputNum(string input);
bool emailValidation(string& a);

// start Vol class
class Vol
{
    private:
        int id;
        string v_id;
        string v_username;
        string v_password;
        string v_fname;
        string v_lname;
        string v_age;
        char v_gender;
        string v_contact;
        string v_email;
        string v_address;
        string v_emergencyName;
        string v_emergencyRel;
        string v_emergencyCon;


    enum invalid_ch
    {
        backspace = 8,
        ret = 13,
        up = 24,
        down = 25,
        right = 26,
        left = 27
    };


    public:
        // automatically creates an ID for a registered volunteer
        void createID()
        {
            fstream idFile;
            idFile.open("v_id.txt");
            idFile.seekg(0,ios::end);   // seek to EOF
            size_t size = idFile.tellg();
            if (size == 0)
            {
                id = 1;
            }
            else
            {
                idFile.seekg(-7,ios::end); // move 5 positions before EOF
                char previous[6];
                idFile.read(previous,5);
                previous[6]=0; // end with NULL character
                // convert char to int
                id = stoi(previous);
                id++;
            }
            ofstream fout;
            fout.open("v_id.txt", ios::app);
            fout << setw(5) << setfill('0') << id << endl;
            fout.close();

            idFile.seekg(-7,ios::end);
            char current[6];
            idFile.read(current,5);
            current[6]=0;
            v_id = convertToString(current,5);
            idFile.close();
        }

        string checkUsername(string &v_username)
        {
            string line,v_user;
            ifstream loginFile;
            loginFile.open("login.txt");
            if(!loginFile)
            {
                cout << "Server Error. Please Try Again.";
            }

            while(!loginFile.eof())
            {
                for (int j=0; j < 2; j++)
                {
                    getline(loginFile,v_user,' ');
                }
                while(v_username == v_user)
                {
                    cout<<"\n\t\t[Username exists] " << endl;
                    cout << "\n\t\tPlease Re-Enter Username: ";
                    cin >> v_username;
                    loginFile.close();
                    checkUsername(v_username);
                }
            }
            loginFile.close();
            return v_username;
        }

        // hides password by converting each char into asterisk
        string hidePass()
        {
            char asterisk = '*';
            string pass = "";
            string con_password = "";
            char password;
            bool regPass;

            while(true)
            {
                password = getch();
                if(password == invalid_ch::ret)
                {
                    cout << endl;
                return pass;
                //check if there is input and if backspace clicked
                }
                else if(password == invalid_ch::backspace && pass.length() != 0)
                {
                    pass.pop_back();
                    cout << "\b \b";
                    //pass.erase(pass.length()-1);
                    continue;
                //check if input is empty and if backspace clicked
                }
                else if(password == invalid_ch::backspace && pass.length() == 0)
                {
                    continue;
                }

                pass.push_back(password);
                cout << asterisk;
                regPass = true;
            }
        }

        // gets user information and save into a txt file
        void registerUser()
        {
            system("CLS");
            string con_pass;
            string line;
            string v_user;
            int atmpt = 2;
            bool registration = false;

            while (registration == false)
            {
                cout << "\n\n\t" << setw(63) << setfill('*') << "*" << endl;
                cout << "\t\t\t  VOLUNTEER MANAGEMENT SYSTEM" << endl;
                cout << "\t" << setw(63) << setfill('*') << "*" << endl;

                cout << "\n\n" << setw(28) << setfill(' ') << " " << "Volunteer Sign Up Page" << endl;
                cout << "\t\t______________________________________________" << endl << endl;
                cout << "\t\tCreate username: " ;
                cin >> v_username;
                checkUsername(v_username);

                cout << "\n\t\tCreate password (min 8 chars.): " ;
                v_password = hidePass();

                while(v_password.length() < 8)
                {
                    cout << "\n\t\t[Password needs to have at least 8 characters]" << endl;
                    cout << "\n\t\tPlease Re-Enter Password: ";
                    v_password = hidePass();
                }

                cout <<"\n\t\tEnter confirmation password: " ;
                con_pass = hidePass();

                if (v_password == con_pass)
                {
                    cout << "\n\n\t\t _____________________________________________\n";
                    cout << "\t\t|                                             |\n";
                    cout << "\t\t|           Registration Successful!          |\n";
                    cout << "\t\t|_____________________________________________|";
                }

                while(v_password != con_pass && atmpt > 0)
                {

                    cout << "\n\t\t[Confirmation password and password do not match]" << endl;
                    cout << "\t\tAttempts left: " << atmpt << endl;
                    cout << "\n\t\tPlease Re-Enter Confirmation Password: ";
                    con_pass = hidePass();
                    cout << endl;


                    atmpt--;

                    if(atmpt == 0 && v_password != con_pass)
                    {
                        cout << "\n\n\t\t______________________________________________" << endl;
                        cout << "\n\t\t                 Entry denied!\n\n";
                        welcomePage();
                    }
                    else if (atmpt < 2 && v_password == con_pass)
                    {
                        cout << "\n\n\t\t _____________________________________________\n";
                        cout << "\t\t|                                             |\n";
                        cout << "\t\t|           Registration Successful!          |\n";
                        cout << "\t\t|_____________________________________________|";
                    }
                }



            cout << "\n\n\n\t\tPlease fill in your details below." << endl << endl;

            cin.ignore();
            cout << "\n\t\tEnter First Name: ";
            getline(cin, v_fname);

            cout << "\n\t\tEnter Last Name: ";
            getline(cin, v_lname);


            cout << "\n\t\tEnter Age: ";
            cin >> v_age;
            if (inputNum(v_age))
            {
                if (stoi(v_age) < 18)
                {
                    cout << "\n\t\t[Registration Unsuccessful - You must be at least 18 years old]" << endl;

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
                while (inputNum(v_age) == 0)
                {
                    cout << "\n\t\t[Please ensure that your input is integer]" << endl;
                    cout << "\n\t\tPlease Re-Enter Your Age:";
                    cin >> v_age;
                }
            }

            cout << "\n\n" << setw(26) << setfill(' ') << " " << "--------------------------";
            cout << "\n" << setw(28) << setfill(' ') << " " << "F - Female";
            cout << "\n" << setw(28) << setfill(' ') << " " << "M - Male";
            cout << "\n" << setw(28) << setfill(' ') << " " << "P - Prefer Not to Say";
            cout << "\n" << setw(26) << setfill(' ') << " " << "--------------------------";
            cout << "\n\n\t\tEnter Gender (F|M|P) : ";
            cin >> v_gender;
            while(v_gender != 'F' && v_gender != 'M' && v_gender != 'P')
            {
                cout << "\n\t\tPlease Enter Gender (F|M|P): ";
                cin >> v_gender;
            }

            cout << "\n\t\tEnter Contact No. (0123456789): ";
            cin >> v_contact;
            while (inputNum(v_contact) == 0)
            {
                cout << "\n\t\t[Invalid Input.Please ensure that your input is numbers]" << endl;
                cout << "\n\t\tPlease Re-Enter Your Contact No.(0123456789):";
                cin >> v_contact;
            }

            cout << "\n\t\tEnter Email: ";
            cin >> v_email;
            bool emailValid = emailValidation(v_email);
            while (emailValid == 0)
            {
                cout << "\n\t\t[Email does not exist]" << endl;
                cout << "\n\t\tPlease Re-Enter Email: ";
                cin >> v_email;
                emailValid = emailValidation(v_email);
            }

            cin.ignore();
            cout << "\n\t\tEnter Full Address: ";
            getline(cin, v_address);

            cout << "\n\n\t\t _____________________________________________\n";
            cout << "\t\t|                                             |\n";
            cout << "\t\t|           Emergency Contact Info            |\n";
            cout << "\t\t|_____________________________________________|";

            cout << "\n\n\n\t\tEnter Emergency Contact Name: ";
            getline(cin, v_emergencyName);

            cout << "\n\t\tEnter Emergency Contact Relationship: ";
            getline(cin, v_emergencyRel);

            cout << "\n\t\tEnter Emergency Contact No. (0123456789): ";
            cin >> v_emergencyCon;
            while (inputNum(v_emergencyCon) == 0)
            {
                cout << "\n\t\t[Invalid Input.Please ensure that your input is numbers]" << endl;
                cout << "\n\t\tPlease Re-Enter Your Contact No. (0123456789):";
                cin >> v_emergencyCon;
            }
                createID();
                ofstream loginF;
                loginF.open("login.txt", ios::app);
                loginF << v_id << " " << v_username << " " << v_password <<endl;
                loginF.close();

            ofstream UserFile;
            UserFile.open("Volunteer/" + v_id + ".txt" , std::ios_base::app);

            UserFile << v_id << ";" << v_fname << ";" << v_lname << ";" << v_age << ";" << v_gender<< ";" <<  v_contact << ";" << v_email
                << ";" << v_address << ";" << v_emergencyName << ";" << v_emergencyRel<< ";" << v_emergencyCon;

            cout << "\n\n\n\n" << setw(27) << setfill(' ') << " " << "*************************" << endl;
            cout << setw(27) << setfill(' ') << " " << "*   ACCOUNT CREATED!   *" << endl;
            cout << setw(27) << setfill(' ') << " " << "*************************" << endl << endl << endl;

            UserFile.close();
            registration = true;
            }
        }

}; // end class


