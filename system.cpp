#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <unistd.h> //sleep
#include <windows.h>
#include "Event.h"
#include "Volunteer.h"
#include "Admin.h"
#include "search.h"
#include "modify.h"
#include "function.h"

using namespace std;

// function declarations
void printHeader();
void welcomePage();
void logIn();
void volunteerMenu();
void volunteerMenu2();
void adminMenu();
void adminMenu2();
bool repeat();
void repeat2();     // return to admin menu
void repeat3();     // return to vol menu

char username[20];
enum invalid_ch{
    backspace = 8,
    ret = 13,
};

// object creations
Vol v;
Event e;
Admin a;

void printHeader()
{
    cout << "\n\n\t" << setw(63) << setfill('*') << "*" << endl;
    cout << "\t\t\t  VOLUNTEER MANAGEMENT SYSTEM" << endl;
    cout << "\t" << setw(63) << setfill('*') << "*" << endl;
}

void welcomePage()
{
    char choice;

    loop:
    system("CLS");
    printHeader();
    cout << "\n\n\t\t          1                       2\n";
    cout << "\t\t    _____________           _____________\n";
    cout << "\t\t   |             |         |             |\n";
    cout << "\t\t   |  Volunteer  |         |    Admin    |\n";
    cout << "\t\t   |_____________|         |_____________|\n";

    cout << "\n\n\n\t\t\t    Enter '0' to exit";
    cout << "\n\n\n\t\t\t  PLEASE CHOOSE (1|2): ";
    cin >> choice;

    switch(choice)
    {
        case '1':
            volunteerMenu();
        break;
        case '2':
            adminMenu();
        break;
        case '0':
            exit(0);
        break;
        default:
            goto loop;
    }
}


void volunteerMenu()
{
    char choiceV;

    loop2:
    system("CLS");
    printHeader();
    cout << "\n\n\t\t\t      Hi Dear Volunteer!\n" << endl;

    cout << "\n\t       1      \t\t       2      \t\t       3      \n";
    cout << "\t ____________ \t\t ____________ \t\t ____________\n";
    cout << "\t|            |\t\t|            |\t\t|            |\n";
    cout << "\t|   Log In   |\t\t|   Sign Up  |\t\t|   Return   |\n";
    cout << "\t|____________|\t\t|____________|\t\t|____________|\n";

    cout << "\n\n\n\t\t\tPLEASE CHOOSE (1|2|3): ";
    cin >> choiceV;


    switch(choiceV)
    {
        case '1':
            logIn();
        break;
        case '2':
            v.registerUser();
        break;
        case '3':
            welcomePage();
        break;
        default:
            goto loop2;
    }
}

void volunteerMenu2()
{
    char choiceV2;
    loop5:

    string id, id2, un, pw, modifyID;
    ifstream loginFile("login.txt");
    //loginFile >> id >> un >> pw;
    while(loginFile >> id >> un >> pw)
    {
        if(username == un)
        {
            id2 = id;
        }
    }


    system("CLS");
    cout << "\n\n\n" << setw(30) << setfill(' ') << " " << "Welcome " << username << "!\n" << endl << endl;
    cout << setw(15) << setfill(' ') << " " << "==============================================" << endl;
    cout << setw(15) << setfill(' ') << " " << "|         What would you like to do?         |" << endl;
    cout << setw(15) << setfill(' ') << " " << "==============================================" << endl << endl;
    cout << setw(20) << setfill(' ') << " " << "I want to..." << endl;
    cout << setw(20) << setfill(' ') << " " << "1. Register for an event" << endl;
    cout << setw(20) << setfill(' ') << " " << "2. Search for an event" << endl;
    cout << setw(20) << setfill(' ') << " " << "3. View profile" << endl;
    cout << setw(20) << setfill(' ') << " " << "4. Edit profile" << endl;
    cout << setw(20) << setfill(' ') << " " << "5. Sign out" << endl << endl;

    cout << "\n\t\t\tPLEASE CHOOSE (1|2|3|4|5): ";
    cin >> choiceV2;

    switch(choiceV2)
    {
        case '1':
            e.selectEvent();
        break;
        case '2':
            system("CLS");
            searchEventMenu();
        break;
        case '3':
            system("CLS");
            viewVolProfile(id2);
        break;
        case '4':
            system("CLS");
            modifyVolAcc(id2);
        break;
        case '5':
            welcomePage();
        break;
        default:
            goto loop5;
    }
}

void adminMenu()
{
    char choiceA;

    loop4:
    system("CLS");
    printHeader();
    cout << "\n\n\t\t\t        Hi Dear Admin!" << endl;

    cout << "\n\n\t\t          1                       2\n";
    cout << "\t\t    _____________           _____________\n";
    cout << "\t\t   |             |         |             |\n";
    cout << "\t\t   |    Log In   |         |    Return   |\n";
    cout << "\t\t   |_____________|         |_____________|\n";

    cout << "\n\n\n\t\t\t  PLEASE CHOOSE (1|2): ";
    cin >> choiceA;

    switch(choiceA)
    {
        case '1':
            a.adminLogIn();
        break;
        case '2':
            welcomePage();
        break;
        default:
            goto loop4;
    }
}

void adminMenu2()
{
    char choiceA2;
    string modifyID;

    loop6:
    system("CLS");

    cout << "\n\n\n" << setw(28) << setfill(' ') << " " << "Welcome Dear Admin!\n" << endl << endl;
    cout << setw(15) << setfill(' ') << " " << "==============================================" << endl;
    cout << setw(15) << setfill(' ') << " " << "|         What would you like to do?         |" << endl;
    cout << setw(15) << setfill(' ') << " " << "==============================================" ;

    cout << "\n\n\t\t\tI want to... " << endl;
    cout << "\t\t\t1. View all volunteers" << endl;
    cout << "\t\t\t2. Search volunteers" << endl;
    cout << "\t\t\t3. Delete volunteer" << endl;
    cout << "\t\t\t4. View all events" << endl;
    cout << "\t\t\t5. Create event" << endl;
    cout << "\t\t\t6. Edit event" << endl;
    cout << "\t\t\t7. Delete event" << endl;
    cout << "\t\t\t8. Sign out" << endl;
    cout << "\n\t\tPLEASE CHOOSE (1|2|3|4|5|6|7|8): ";
    cin >> choiceA2;

    switch(choiceA2)
    {
        case '1':
            loop7:
            system("CLS");
            sortVolID(true);
            char sortchoice;
            cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t Sort list by: " << endl;
            cout << "\t\t\t\t\t\t\t_______________________________\n" << endl;
            cout << "\t\t\t\t\t\t\t  1. ID, ascending" << endl;
            cout << "\t\t\t\t\t\t\t  2. ID, descending" << endl;
            cout << "\t\t\t\t\t\t\t  3. First name, ascending" << endl;
            cout << "\t\t\t\t\t\t\t  4. First name, descending" << endl;
            cout << "\t\t\t\t\t\t\t  5. Age, ascending" << endl;
            cout << "\t\t\t\t\t\t\t  6. Age, descending" << endl;
            cout << "\t\t\t\t\t\t\t  7. Return" << endl;
            cout << "\n\t\t\t\t\t\t\t  PLEASE CHOOSE (1|2|3|4|5|6|7): ";
            cin >> sortchoice;

            switch(sortchoice)
            {
                case '1':
                    system("CLS");
                    sortVolID(true);
                    repeat2();
                break;
                case '2':
                    system("CLS");
                    sortVolID(false);
                    repeat2();
                break;
                case '3':
                    system("CLS");
                    sortVolFname(true);
                    repeat2();
                break;
                case '4':
                    system("CLS");
                    sortVolFname(false);
                    repeat2();
                break;
                case '5':
                    system("CLS");
                    sortVolAge(true);
                    repeat2();
                break;
                case '6':
                    system("CLS");
                    sortVolAge(false);
                    repeat2();
                break;
                case '7':
                    adminMenu2();
                break;
                default:
                    goto loop7;
            }
        break;
        case '2':
            system("CLS");
            searchVolMenu();    // search volunteer
        break;
        case '3':
            system("CLS");
            a.deleteVol();  // delete volunteer
        break;
        case '4':
            system("CLS");
            displayEvents();     // view all events
        break;
        case '5':
            system("CLS");
            e.createEvent();
        break;
        case '6':
            system("CLS");
            printHeader();
            cout << "\n\n" << setw(22) << setfill(' ') << " " << "Please fill in your details below" << endl;
            cout << "\t\t______________________________________________" << endl << endl;
            cout << "\n\t\tEnter event ID to be edited: ";
            cin >> modifyID;
            modifyEvent(modifyID);
            // modify/edit events
        break;
        case '7':
            system("CLS");
            a.deleteEvent();
            // delete events
        break;
        case '8':
            welcomePage();
        break;
        case '9':
            adminMenu2();
        break;
        default:
            goto loop6;
    }
}

string hidePass()
{
    char asterisk = '*';
    string pass = "";
    char password;
    bool regPass;

    while(true)
    {
        password = getch();
        if(password == invalid_ch::ret)
        {
            cout << endl;
            return pass;
            // check if there is input and if backspace clicked
        }
        else if(password == invalid_ch::backspace && pass.length() != 0)
        {
            pass.pop_back();
            cout << "\b \b";
            // pass.erase(pass.length()-1);
            continue;
            // check if input is empty and if backspace clicked
        }
        else if(password == invalid_ch::backspace && pass.length() == 0)
        {
            continue;
        }
        pass.push_back(password);
        cout << asterisk;
    }
}

void logIn()
{
    system("CLS");
    string pass;
    char password[20];
    char storedUser[20];
    char storedPass[20];
    int attempt=1;

    printHeader();

    cout << "\n\n" << setw(28) << setfill(' ') << " " << "Volunteer Log In Page" << endl;
    cout << "\t\t______________________________________________" << endl;



    ifstream loginFile("login.txt");
    if (!loginFile)
    {
        cout << "\n\t\tServer Error. Please try again later.";
        exit(0);
    }

    cout << "\n\t\tUsername: ";
    cin >> username;
    // check characters if the username is equal to storedUser
    // strcmp will return 0 if equals

    while(strcmp(username,storedUser))
    {
        loginFile >> storedUser;

        if(loginFile.eof())
        {
            cout << "\n\t\t[Error: Username does not exist.]\n" << endl;
            usleep(1000000); //2 seconds
            //system("PAUSE");
            // bring back to login
            welcomePage();
        }
    }
    /** username and password are at the same line,
    store the input next to the username */
    loginFile>>storedPass;

    cout << "\n\t\tPassword: ";
    pass = hidePass();
    password[pass.length()];

    for(int i=0; i<sizeof(password); i++)
    {
        password[i] = pass[i];
    }

    while(strcmp(password,storedPass) && attempt < 3)
    {
        cout << "\n\t\t[Incorrect Password]" << endl;
        cout << "\n\t\tAttempts: " << (attempt+1) << endl;
        cout << "\n\t\tPlease Re-Enter Password: ";
        pass = hidePass();
        memset(password,0,sizeof(password));
        password[pass.length()];
        for(int i=0; i<sizeof(password); i++)
        {
            password[i] = pass[i];
        }
        attempt++;
    }

    if(attempt > 2)
    {
        cout << "\n\t\tLogin attempt exceeded three times!";
        usleep(2000000);
        //usleep(5e+6);
        //BACK TO MENU,
        welcomePage();
    }

    cout << "\n\n\t\t _____________________________________________\n";
    cout << "\t\t|                                             |\n";
    cout << "\t\t|           Login Successful!                 |\n";
    cout << "\t\t|_____________________________________________|";
    cout << endl << endl;
    usleep(1000000);
    //usleep(5000000);
    //system("PAUSE");
    volunteerMenu2();
}

bool repeat()
{
    string choiceR;

    cout << "\n\n\n\n\n" << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << setw(25) << setfill(' ') << " " << "|    What would you like to do?    |" << endl;
    cout << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 1. Back to Main Menu             |" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 2. Exit program                  |" << endl;
    cout << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << "\n\t\t\tEnter your choice: ";

    cin >> choiceR;

    bool repeat;
    try
    {
        if (choiceR == "2")
        {
            repeat = false;
            cout << "\n\n\t\tThank you for using our system, Bye!\n\n";
            return repeat;
        }
        else if (choiceR == "1")
        {
            repeat = true;
            return repeat;
        }
        else if(choiceR != "1" || choiceR != "2")
        {
            throw 1;
        }
    }

    catch(int x)
    {
        do
        {
            cout << "\n\n\t\t\t[Invalid input!]" << endl;
            cout << "\t\t\tPlease enter your choice again (1|2): ";
            cin >> choiceR;
            if (choiceR == "2")
            {
                repeat = false;
                cout << endl << endl;
                cout << "\n\t\t\tThank you for using our system, Bye!\n\n" << endl << endl;
                return repeat;
            }
            else if (choiceR == "1")
            {
                repeat = true;
                return repeat;
            }
        }while (choiceR != "1" && choiceR != "2");
    }
    return 0;
}

void repeat2()
{
    string choiceR2;

    cout << "\n\n\n\n\n" << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << setw(25) << setfill(' ') << " " << "|    What would you like to do?    |" << endl;
    cout << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 1. Back to Main Menu             |" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 2. Exit program                  |" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 3. Return                        |" << endl;
    cout << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << "\n\t\t\t    Enter your choice (1|2|3): ";

    cin >> choiceR2;

    try
    {
        if (choiceR2 == "1")
        {
            welcomePage();

        }
        else if (choiceR2 == "2")
        {
            cout << "\n\n\t\t\tThank you for using our system, Bye!\n\n";
            exit(0);
        }
        else if (choiceR2 == "3")
        {
            adminMenu2();
        }
        else if(choiceR2 != "1" || choiceR2 != "2" || choiceR2 != "3")
        {
            throw 1;
        }
    }

    catch(int x)
    {
        do
        {
            cout << "\n\n\t\t\t[Invalid input!]" << endl;
            cout << "\t\t\tPlease enter your choice again (1|2|3): ";
            cin >> choiceR2;
            if (choiceR2 == "1")
            {
                welcomePage();
            }
            else if (choiceR2 == "2")
            {
                cout << endl << endl;
                cout << "\n\n\t\t\tThank you for using our system, Bye!\n\n" << endl << endl;
                exit(0);
            }
            else if (choiceR2 == "3")
            {
                adminMenu2();
            }
        }while (choiceR2 != "1" && choiceR2 != "2" && choiceR2 != "3");
    }
}

void repeat3()
{
    string choiceR2;

    cout << "\n\n\n\n\n" << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << setw(25) << setfill(' ') << " " << "|    What would you like to do?    |" << endl;
    cout << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 1. Back to Main Menu             |" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 2. Exit program                  |" << endl;
    cout << setw(25) << setfill(' ') << " " << "| 3. Return                        |" << endl;
    cout << setw(25) << setfill(' ') << " " << setw(36) << setfill('=') << "=" << endl;
    cout << "\n\t\t\t  Enter your choice (1|2|3): ";

    cin >> choiceR2;

    try
    {
        if (choiceR2 == "1")
        {
            welcomePage();

        }
        else if (choiceR2 == "2")
        {
            cout << "\n\n\t\t\tThank you for using our system, Bye!\n\n";
            exit(0);
        }
        else if (choiceR2 == "3")
        {
            volunteerMenu2();
        }
        else if(choiceR2 != "1" || choiceR2 != "2" || choiceR2 != "3")
        {
            throw 1;
        }
    }

    catch(int x)
    {
        do
        {
            cout << "\n\n\t\t\t[Invalid input!]" << endl;
            cout << "\t\t\tPlease enter your choice again (1|2|3): ";
            cin >> choiceR2;
            if (choiceR2 == "1")
            {
                welcomePage();
            }
            else if (choiceR2 == "2")
            {
                cout << endl << endl;
                cout << "\n\n\t\t\tThank you for using our system, Bye!\n\n" << endl << endl;
                exit(0);
            }
            else if (choiceR2 == "3")
            {
                volunteerMenu2();
            }
        }while (choiceR2 != "1" && choiceR2 != "2" && choiceR2 != "3");
    }
}

// main function
int main()
{

    SetConsoleTitleA("Volunteer Management System");

    do
    {
        system("CLS");
        welcomePage();

    } while (repeat() == true);


    return 0;
}
