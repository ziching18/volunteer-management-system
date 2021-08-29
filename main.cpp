# include <iostream>
# include <cstdlib>
using namespace std;

void welcomePage()
{
    int n;
    cout << "\n\n" << endl;
    cout << "\t\tWelcome to" << endl;
    cout << "\t    Hot Babes Presents" << endl;
    cout << "\tVOLUNTEER MANAGEMENT SYSTEM" << endl;
    cout << "\n\n" << endl;
    cout << "\t\tI am..." << endl;
    cout << "\t\t1. A volunteer" << endl;
    cout << "\t\t2. An organiser" << endl;
    cout << "\t\t3. An admin" << endl << endl;
    cout << "\t   >> ";
    cin >> n;
}

void volunteerMenu()
{
    int n;
    cout << "\n\n" << endl;
    cout << "\t   I am a volunteer" << endl;
    cout << "\t\tI want to..." << endl;
    cout << "\t\t1. Register for an event" << endl;
    cout << "\t\t2. View application history" << endl;
    cout << "\t\t3. View profile" << endl;
    cout << "\t\t4. Sign out" << endl << endl;
    cout << "\t   >> ";
    cin >> n;
}

void organiserMenu()
{
    int n;
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
    cin >> n;
}

void adminMenu()
{
    int n;
    cout << "\n\n" << endl;
    cout << "\t   I am an admin\n" << endl;
    cout << "\t\tI want to..." << endl;
    cout << "\t\t1. View all events" << endl;
    cout << "\t\t2. View all volunteers" << endl;
    cout << "\t\t3. View all organisers" << endl;
    cout << "\t\t4. Sign out" << endl << endl;
    cout << "\t   >> ";
    cin >> n;
}


int main()
{
    welcomePage();
    volunteerMenu();
    organiserMenu();
    adminMenu();
    system("pause");
    cout << "\n\n\n\n";
    return 0;
}
