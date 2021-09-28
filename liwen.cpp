#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void printHeader();
void welcomePage();
void logInMenu();
void volunteerMenu();
void organiserMenu();
void adminMenu();
bool repeat();

void printHeader()
{
    cout << "\n\n\t" << setw(63) << setfill('*') << "*" << endl;
    cout << "\t\t\t  VOLUNTEER MANAGEMENT SYSTEM" << endl;
    cout << "\t" << setw(63) << setfill('*') << "*" << endl;
}

void welcomePage()
{
    int choice;

    loop:
    system("CLS");
    printHeader();
    cout << "\n" << setw(17) << setfill(' ') << "1" << setw(23) << setfill(' ') << "2" << setw(25) << setfill(' ') << "3\n";
    cout << "\t _____________\t\t _____________\t\t _____________\n";
    cout << "\t|             |\t\t|             |\t\t|             |\n";
    cout << "\t|  Volunteer  |\t\t|  Organiser  |\t\t|    Admin    |\n";
    cout << "\t|_____________|\t\t|_____________|\t\t|_____________|\n";

    cout << "\n\n\n\t\t\tPLEASE CHOOSE (1|2|3): ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            volunteerMenu();
        break;
        case 2:
            organiserMenu();
        break;
        case 3:
            adminMenu();
        break;
        default:
            goto loop;
    }
}

void logInMenu()
{
    cout << "\n" << setw(16) << setfill(' ') << "1" << setw(23) << setfill(' ') << "2" << setw(25) << setfill(' ') << "3\n";
    cout << "\t ____________\t\t ____________\t\t ____________\n";
    cout << "\t|            |\t\t|            |\t\t|            |\n";
    cout << "\t|   Log In   |\t\t|   Sign Up  |\t\t|   Return   |\n";
    cout << "\t|____________|\t\t|____________|\t\t|____________|\n";
}


void volunteerMenu()
{
    int choiceV;

    loop2:
    system("CLS");
    printHeader();
    cout << "\n\n" << setw(48) << setfill(' ')<< "Hi Dear Volunteer!\n" << endl;

    logInMenu();

    cout << "\n\n\n\t\t\tPLEASE CHOOSE (1|2|3): ";
    cin >> choiceV;


    switch (choiceV)
    {
        case 1:
            cout <<"I am log in";
        break;
        case 2:
            cout <<"I am sign up";
        break;
        case 3:
            welcomePage();
        break;
        default:
            goto loop2;
    }


}

void volunteerMenu2()
{
    cout << "\t\t====================================" << endl;
    cout << "\t\t|    What would you like to do?    |" << endl;
    cout << "\t\t====================================" << endl;
    cout << "\t\tI want to..." << endl;
    cout << "\t\t1. Register for an event" << endl;
    cout << "\t\t2. View application history" << endl;
    cout << "\t\t3. View profile" << endl;
    cout << "\t\t4. Sign out" << endl << endl;
    cout << "\t   >> ";




}
void organiserMenu()
{
    int choiceO;
    loop3:
    system("CLS");
    printHeader();
    cout << "\n\n" << setw(48) << setfill(' ')<< "Hi Dear Organizer!\n" << endl;

    logInMenu();

    cout << "\n\n\n\t\t\tPLEASE CHOOSE (1|2|3): ";
    cin >> choiceO;

    switch (choiceO)
    {
        case 1:
            cout <<"I am log in";
        break;
        case 2:
            cout <<"I am sign up";
        break;
        case 3:
            welcomePage();
        break;
        default:
            goto loop3;
    }

}

void organiserMenu2()
{
    cout << "\n\n" << endl;
    cout << "\t   I am an organiser\n" << endl;
    cout << "\t\tI want to..." << endl;
    cout << "\t\t1. Create an event" << endl;
    cout << "\t\t2. Delete an event" << endl;
    cout << "\t\t3. View all events" << endl;
    cout << "\t\t4. View all volunteers" << endl;
    cout << "\t\t5. View profile" << endl;
    cout << "\t\t6. Sign out" << endl << endl;
    cout << "\t   >> ";

}
void adminMenu()
{
    int choiceA;

    loop4:
    system("CLS");
    printHeader();
    cout << "\n\n" << setw(48) << setfill(' ')<< "Hi Dear Admin!\n" << endl;

    logInMenu();

    cout << "\n\n\n\t\t\tPLEASE CHOOSE (1|2|3): ";
    cin >> choiceA;

    switch (choiceA)
    {
        case 1:
            cout <<"I am log in";
        break;
        case 2:
            cout <<"I am sign up";
        break;
        case 3:
            welcomePage();
        break;
        default:
            goto loop4;
    }

    /*cout << "\t   I am an admin\n" << endl;
    cout << "\t\tI want to..." << endl;
    cout << "\t\t1. View all events" << endl;
    cout << "\t\t2. View all volunteers" << endl;
    cout << "\t\t3. View all organisers" << endl;
    cout << "\t\t4. Sign out" << endl << endl;
    cout << "\t   >> ";
    cin >> choice;*/
}

bool repeat()
{
    int choiceR;

    cout << endl;
    cout << "\t\t====================================" << endl;
    cout << "\t\t|    What would you like to do?    |" << endl;
    cout << "\t\t====================================" << endl;
    cout << "\t\t| 1. Back to Main Menu             |" << endl;
    cout << "\t\t| 2. Exit program                  |" << endl;
    cout << "\t\t====================================" << endl;
    cout << "\t\tEnter your choice: ";

    cin >> choiceR;

    bool repeat;
    try
    {
        if (choiceR == 2)
        {
            repeat = false;
            cout << "\n\n\t\tThank you for using our system, Bye!";
            return repeat;
        }
        else if (choiceR == 1)
        {
            repeat = true;
            return repeat;
        }
        else if(choiceR != 1 || choiceR != 2)
        {
            throw 1;
        }
    }

    catch(int x)
    {
        do
        {
            cout << "\t\tInvalid input!" << endl;
            cout << "Please enter your choice again [1|2]: ";
            cin >> choiceR;
            if (choiceR == 2)
            {
                repeat = false;
                cout << endl << endl;
                cout << "\t\tThank you for using our system, Bye!" << endl << endl;
                return repeat;
            }
            else if (choiceR == 1)
            {
                repeat = true;
                return repeat;
            }
        }while (choiceR != 1 && choiceR != 2);
    }
    return 0;
}


int main()
{
    do
    {
        system("CLS");
        welcomePage();

    }while (repeat() == true);

    return 0;

}
