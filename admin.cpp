#include <iostream>
#include <regex>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include "newsort.cpp"
//#include "newview.cpp"
using namespace std;

class Admin
{
    private:

        string username = "admin";
        string password = "iloveliwen";

    public:

        enum invalid_ch
        {
            backspace = 8,
            ret = 13,
            up = 24,
            down = 25,
            right = 26,
            left = 27
        };

        string hidePass()
        {
            char asterisk = '*';
            string pass = "";
            string con_password = "";
            char password;
            bool regPass;

            while(true) {
                password = getch();
                if (password == invalid_ch::ret) {
                    cout << endl;
                    return pass;
                }
                else if (password == invalid_ch::backspace && pass.length() != 0) {
                    pass.pop_back();
                    cout << "\b \b";
                    continue;
                }
                else if(password == invalid_ch::backspace && pass.length() == 0){
                    continue;
                }
                pass.push_back(password);
                cout << asterisk;
                regPass = true;
            }

        }

        void adminLogIn()
        {
            int atmpt = 2;

            cout << "\n\n" << setw(28) << setfill(' ') << " " << "Admin Log In Page" << endl;
            cout << "\t\t______________________________________________" << endl;
            string uname, pswd;
            cout << "\n\t\tPlease enter the username: ";
            cin >> uname;

            cout << "\t\tPlease enter the password: ";
            pswd = hidePass();
            cout << endl;

            if (uname == username && pswd == password) {
                cout << "\t\tLog in successful!" << endl;
                adminMenu();
            }
            else {
                //cout << "\t\tWho are you and why are you invading the system" << endl;
                while ((uname != username || pswd != password) && atmpt > 0) {
                cout << "\n\t\tWrong credentials. Please try again." << endl;
                cout << "\t\tAttempts left: " << atmpt << endl;
                cout << "\n\t\tPlease enter the username: ";
                cin >> uname;

                cout << "\t\tPlease enter the password: ";
                pswd = hidePass();
                cout << endl;

                atmpt--;

                if(atmpt == 0 && uname != username && pswd != password)
                {
                    cout << "\n\t\tLogin attempt exceeded three times!";
                    cout << "\n\t\tEntry denied. System will now terminate.\n\n";
                }
                else if (atmpt == 0 && uname == username && pswd == password)
                {
                    cout << "\t\tLog in successful!" << endl;
                    adminMenu();
                }
            }
        }

            //
        }

        /**
        void adminMenu()
        {
            system("pause");
            system("CLS");
            int choice;
            cout << "\n\n\t\t\tChoose something to do: " << endl;
            cout << "\t\t\t1. View all volunteers" << endl;
            cout << "\t\t\t2. Delete volunteer" << endl;
            cout << "\t\t\t3. View all events" << endl;
            cout << "\t\t\t4. Delete event" << endl;
            cout << "\t\t\t5. Create event" << endl;
            cin >> choice;

            switch(choice)
            {
                case 1:
                    system("CLS");
                    sortVolID(true);
                    int sortchoice;
                    cout << "\n\n\t\t\tSort list by: " << endl;
                    cout << "\t\t\t1. ID, ascending" << endl;
                    cout << "\t\t\t2. ID, descending" << endl;
                    cout << "\t\t\t3. First name, ascending" << endl;
                    cout << "\t\t\t4. First name, descending" << endl;
                    cout << "\t\t\t5. Age, ascending" << endl;
                    cout << "\t\t\t6. Age, ascending" << endl;
                    cout << "\t\t\t>> ";
                    cin >> sortchoice;

                    switch(sortchoice) {
                        case 1:
                            system("CLS");
                            sortVolID(true);
                        break;
                        case 2:
                            system("CLS");
                            sortVolID(false);
                        break;
                        case 3:
                            system("CLS");
                            sortVolFname(true);
                        break;
                        case 4:
                            system("CLS");
                            sortVolFname(false);
                        break;
                        case 5:
                            system("CLS");
                            sortVolAge(true);
                        break;
                        case 6:
                            system("CLS");
                            sortVolAge(false);
                        break;
                    }

                    break;
                case 2:
                    system("CLS");
                    displayEvents();
                    break;

            }
        }
        //**/

};

int main()
{
    SetConsoleTitleA("Admin");
    Admin abang;
    abang.adminLogIn();
    return 0;
}
