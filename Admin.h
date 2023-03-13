#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h> //sleep

using namespace std;

void adminMenu2();
void printHeader();

//-------------Volunteer-------------

void delVolID(string id)
{
    string line;
    ifstream fileName;
    fileName.open("v_id.txt");
    ofstream temp;
    temp.open("temp.txt");

    if(!temp)   // temp not opened
    {
        cout << "Temp file cannot be opened.";
    }

    if(!fileName)   // fileName not opened
    {
        cout << "FileName cannot be opened.";
    }
    // check whether volunteer ID exists
    while(getline(fileName,line))
    {
        if(line != id)
        {
            temp << line << endl;
        }
    }

    fileName.close();
    temp.close();
    remove("v_id.txt");
    rename("temp.txt","v_id.txt");
}

void delVolUserPass(string id)
{
    string line;
    ifstream loginFile;
    loginFile.open("login.txt");
    ofstream temp;
    temp.open("temp.txt");

    if(!temp)   // temp not opened
    {
        cout << "Temp file cannot be opened.";
    }

    if(!loginFile)   // loginFile not opened
    {
        cout << "Login file cannot be opened.";
    }

    while(getline(loginFile,line))
    {
        if(line.find(id) != string::npos)
        {
            continue;
        }else
        {
            temp << line << endl;
        }
    }
    loginFile.close();
    temp.close();
    remove("login.txt");
    rename("temp.txt","login.txt");
}

void delVolInfo(string id)
{
    string fileName = "Volunteer\\" + id + ".txt";
    int length = fileName.length();
    char file[length+1];
    strcpy(file,fileName.c_str());
    remove(file);
}

//----------------Event------------------

void delEventID(string id)
{
    string line;
    ifstream fileName;
    fileName.open("e_id.txt");
    ofstream temp;
    temp.open("temp.txt");

    if(!temp)   // temp not opened
    {
        cout << "Temp file cannot be opened.";
    }

    if(!fileName)   // fileName not opened
    {
        cout << "FileName cannot be opened.";
    }
    // check whether event ID exists
    while(getline(fileName,line))
    {
        if(line != id)
        {
            temp << line << endl;
        }
    }

    fileName.close();
    temp.close();
    remove("e_id.txt");
    rename("temp.txt","e_id.txt");
}

void delEventName(string id)
{
    string e_name,line;
    // get event name
    ifstream infoFile;
    infoFile.open("Event\\" + id + ".txt");
    // open temporary file
    ofstream temp;
    temp.open("temp.txt");
    // open event name file
    ifstream eNameFile;
    eNameFile.open("eventName.txt");

    if(!infoFile)   // infoFile not opened
    {
        cout << "File cannot be opened.";
    }

    for(int i=0; i <2; i++)
    {
        getline(infoFile, e_name, ';'); // use ; as delimiter
    }
    infoFile.close();

    if(!eNameFile)  //eNameFile not opened
    {
        cout << "File cannot be opened.";
    }

    while(getline(eNameFile,line))
    {
        // name exists
        if(line.find(e_name) != string::npos)
        {
            continue;
        }
        temp << line << endl;
    }
    eNameFile.close();
    temp.close();
    remove("eventName.txt");
    rename("temp.txt","eventName.txt");
}

void delEventInfo(string id)
{
    string fileName = "Event\\" + id + ".txt";
    int length = fileName.length();
    char file[length+1];
    strcpy(file,fileName.c_str());
    remove(file);
}

// start Admin class
class Admin
{
    private:
        const string username = "admin";
        const string password = "iloveliwen";

    public:
        enum invalid_ch
        {
            backspace = 8,
            ret = 13,
        };

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
                if (password == invalid_ch::ret)
                {
                    cout << endl;
                    return pass;
                }
                else if (password == invalid_ch::backspace && pass.length() != 0)
                {
                    pass.pop_back();
                    cout << "\b \b";
                    continue;
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

        void adminLogIn()
        {
            system("CLS");

            int atmpt = 2;

            printHeader();

            cout << "\n\n" << setw(30) << setfill(' ') << " " << "Admin Log In Page" << endl;
            cout << "\t\t______________________________________________" << endl;
            string uname, pswd;
            cout << "\n\n\t\tUsername: ";
            cin >> uname;

            cout << "\n\t\tPassword: ";
            pswd = hidePass();
            cout << endl;

            if (uname == username && pswd == password)
            {
                cout << "\n\t\tLog in successful!" << endl;
                usleep(1000000);
                adminMenu2();
            }
            else
            {
                //cout << "\t\tWho are you and why are you invading the system" << endl;
                while ((uname != username || pswd != password) && atmpt > 0) {
                    cout << "\n\t\t[Wrong credentials. Please try again.]" << endl;
                    cout << "\t\tAttempts left: " << atmpt << endl;
                    cout << "\n\t\tPlease re-enter the username: ";
                    cin >> uname;

                    cout << "\n\t\tPlease re-enter the password: ";
                    pswd = hidePass();
                    cout << endl;

                    atmpt--;

                    if(atmpt == 0 && uname != username && pswd != password)
                    {
                        cout << "\n\n\t\t______________________________________________" << endl;
                        cout << "\n\t\tLogin attempt exceeded three times!";
                        cout << "\n\t\tEntry denied. System will now terminate.\n\n";
                        usleep(1000000);
                    }
                    else if (atmpt < 2 && uname == username && pswd == password)
                    {
                        cout << "\n\t\tLogin successful!" << endl;
                        adminMenu2();
                    }
                }
            }

        }

        // delete volunteer from system database
        void deleteVol()
        {
            char option;
            string userID;
            string usernameInput;
            string passwordInput;
            string checkID;
            bool found = false;

            printHeader();
            cout << "\n\n\t\t                Delete a volunteer" << endl;
            cout << "\t\t______________________________________________" << endl << endl;

            cout << "\t\tEnter volunteer ID: ";
            cin >> userID;
            cout << "\n\n\n\t\t-------------------[AUTH]---------------------" << endl;
            cout << "\n\t\tEnter username: ";
            cin >> usernameInput;
            cout << "\n\t\tEnter password: ";
            passwordInput = hidePass();

            if (usernameInput == username && passwordInput == password)
            {
                loop10:
                cout << "\n\n\n\t\tAre you sure that you want to delete file of Volunteer " << userID << "? (y|n): ";
                cin >> option;
                switch(option)
                {
                    case 'Y':
                    case 'y':
                        {
                            ifstream fileName;
                            fileName.open("v_id.txt");
                            // check if ID exists
                            while(fileName >> checkID)
                            {
                                if (userID == checkID)
                                {
                                    found = true;
                                    break;
                                }
                            }
                            fileName.close();

                            if (found == false)
                            {
                                cout << "\n\n\t\t\t[Volunteer does not exist]";
                                repeat2();
                            }
                            else
                            {
                                delVolID(userID);
                                delVolUserPass(userID);
                                delVolInfo(userID);
                                cout << "\n\n\t\t\t[Volunteer account has been deleted]";
                                repeat2();
                            }
                        }

                        break;

                    case 'N':
                    case 'n':
                        {
                            cout << "\n\n\t\t\t[You will be brought back to main menu]";
                            repeat2();
                        }
                        break;
                    default :
                        cout << "\n\n\t\t\t[Please enter 'Y' or 'N' only]";
                        goto loop10;
                }
            }
            else
            {
                cout << "\n\n\t\t\t[Authorisation failed]";
                cout << "\n\n\t\t\t[Unable to delete file]";
                repeat2();
            }

        }

        // delete event from system database
        void deleteEvent()
        {
            char option;
            string eventID;
            string usernameInput;
            string passwordInput;
            string checkID;
            bool found = false;

            printHeader();
            cout << "\n\n\t\t               Delete an event" << endl;
            cout << "\t\t______________________________________________" << endl << endl;

            cout << "\t\tEnter event ID: ";
            cin >> eventID;
            cout << "\n\n\n\t\t-------------------[AUTH]---------------------" << endl;
            cout << "\n\t\tEnter username: ";
            cin >> usernameInput;
            cout << "\n\t\tEnter password: ";
            passwordInput = hidePass();

            if (usernameInput == username && passwordInput == password)
            {
                loop11:
                cout << "\n\n\n\t\tAre you sure that you want to delete file of Event ID " << eventID << "? (Y|N): ";
                cin >> option;
                switch(option)
                {
                    case 'Y' :
                    case 'y' :
                        {
                            ifstream fileName;
                            fileName.open("e_id.txt");
                            while(fileName >> checkID)
                            {
                                if (eventID == checkID)
                                {
                                    found = true;
                                    break;
                                }
                            }
                            fileName.close();

                            if (found == false)
                            {
                                cout << "\n\n\t\t\t[Event does not exist]";
                                repeat2();
                            }
                            else
                            {
                                delEventID(eventID);
                                delEventName(eventID);
                                delEventInfo(eventID);
                                cout << "\n\n\t\t\t[Event has been deleted]";
                                repeat2();
                            }
                        }
                        break;

                    case 'N' :
                    case 'n' :
                        {
                            cout << "\n\n\t\t\t[You will be brought back to main menu]";
                            repeat2();
                        }
                        break;
                    default :
                        cout << "\n\n\t\t\t[Please enter 'Y' or 'N' only]";
                        goto loop11;
                }
            }
            else
            {
                cout << "\n\n\t\t\t[Authorisation failed]";
                cout << "\n\n\t\t\t[Unable to delete file]";
                repeat2();
            }
        }
};  // end class
