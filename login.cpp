#include <iostream>
#include <string>
#include <fstream> //used to create,write and read files
#include <cstring>
using namespace std;

int main(){
    char username[20];
    char password[20];
    char storedUser[20];
    char storedPass[20];
    int attempt=0;

    while(attempt < 3){
        ifstream loginFile("login.txt");
        if (!loginFile){
            cout << "Server Error. Please try again later.";
            return 0;
        }

        cout << "Username : ";
        cin >> username;
        //check characters if the username is equal to storedUser
        //strcmp will return 0 if equals
        while(strcmp(username,storedUser)){
            loginFile >> storedUser;
            if(loginFile.eof()){
                cout << "Username does not exist." << endl;
                //bring back to login
                cout << "Would you like to try again?";
                //ADD MENU TO BRING TO LOGIN
            }
        }
        /*username and password are at the same line,
        store the input next to the username */
        loginFile>>storedPass;


        cout << "Password : ";
        cin >> password;
        while(strcmp(password,storedPass)){
            cout << "Wrong Password." << endl;
            cout << "Please Re-Enter Password : ";
            cin >> password;
        }
        cout << "Login Successful." << endl;
    }



}
