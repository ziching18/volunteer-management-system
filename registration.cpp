#include <iostream>
#include <string>
#include <fstream> //used to create,write and read files
#include <conio.h> //used to call getch()
#include <regex> //regex, regex_match
using namespace std;


class Vol{
  private:
    int id;
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


    enum invalid_ch{
        backspace = 8,
        ret = 13,
        up = 24,
        down = 25,
        right = 26,
        left = 27
    };

  public:

    bool inputNum(string input){
        for (int i = 0; i < input.length(); i++){
            if (isdigit(input[i]) == false){
                return false;
            }
        }
        return true;
    }

    bool emailValidation(string& v_email){
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(v_email,pattern);
    }

    string hidePass(){
        char asterisk = '*';
        string pass = "";
        string con_password = "";
        char password;
        bool regPass;

        while(true){
            password = getch();
            if(password == invalid_ch::ret){
                cout << endl;
                /*if(pass.length() < 8){
                   cout << "Password need to have at least 8 characters.";
                   cout << endl;
                }else{
                    return pass;
                }*/
                return pass;
            //check if there is input and if backspace clicked
            }else if(password == invalid_ch::backspace && pass.length() != 0){
                pass.pop_back();
                cout << "\b \b";
                //pass.erase(pass.length()-1);
                continue;
            //check if input is empty and if backspace clicked
            }else if(password == invalid_ch::backspace && pass.length() == 0){
                continue;
            }
            pass.push_back(password);
            cout << asterisk;
            regPass = true;
        }

    }


    void registerUser(){

        string con_pass;
        bool registration = false;

        while (registration == false){
            cout << "Enter username : " ;
            cin >> v_username;

            /*do{
                cout << "Enter password : " ;
                v_password = hidePass();
            }while(v_password.length() < 8);*/
            cout << "Enter password : " ;
            v_password = hidePass();
            while(v_password.length() < 8){
                cout << "Password needs to have at least 8 characters." << endl;
                cout << "Please Re-Enter Password : ";
                v_password = hidePass();
            }

            cout <<"Enter confirmation password : " ;
            con_pass = hidePass();
            while(v_password != con_pass){
                cout << "Confirmation password and password is not similar. Please try again." << endl;
                cout << "Please Re-Enter Confirmation Password : ";
                con_pass = hidePass();
            }
            ofstream UserFile;
            UserFile.open("C:/Users/user/Downloads/C++/Volunteer/" + v_username + ".txt"); //change directory
            UserFile << v_username << "," << v_password <<endl;
            registration = true;

        }
        cout << "Registration Successful." << endl;
        cout << "Please fill in your details below." << endl << endl;

        cout << "Enter First Name : ";
        cin >> v_fname;

        cout << "Enter Last Name : ";
        cin >> v_lname;


        cout << "Enter Age : ";
        cin >> v_age;

        if (inputNum(v_age)){
            if (stoi(v_age) < 18){
                cout << "Registration Unsuccessful - You must be at least 18 years old." << endl;
                exit(0);
            }
        }else{
            while (inputNum(v_age) == 0){
                cout << "Please ensure that your input is integer.";
                cout << "Please Re-Enter Your Age :";
                cin >> v_age;
            }
        }

        cout << " F - female \n M - male \n P - Prefer Not to Say" << endl;
        cout << "Enter Gender (F/M/P) : ";
        cin >> v_gender;
        while(v_gender != 'f' && v_gender != 'F' && v_gender != 'm' && v_gender != 'M' && v_gender != 'p' && v_gender != 'P'){
            cout << "Please Enter Gender (F/M/P) : ";
            cin >> v_gender;
        }

        cout << "Enter Contact No. : ";
        cin >> v_contact;
        while (inputNum(v_contact) == 0){
            cout << "Invalid Input.Please ensure that your input is numbers." << endl;
            cout << "Please Re-Enter Your Contact No. :";
            cin >> v_contact;
        }

        cout << "Enter Email : ";
        cin >> v_email;
        bool emailValid = emailValidation(v_email);
        while (emailValid == 0){
            cout << "Email does not exist. Please Re-Enter Email : ";
            cin >> v_email;
            emailValid = emailValidation(v_email);
        }


        cout << "Enter Full Address : ";
        cin >> v_address;

        cout << "Enter Emergency Contact Name : ";
        cin >> v_emergencyName;
        cout << "Enter Emergency Contact Relationship : ";
        cin >> v_emergencyRel;
        cout << "Enter Emergency Contact No. : ";
        cin >> v_emergencyCon;
        while (inputNum(v_emergencyCon) == 0){
            cout << "Invalid Input.Please ensure that your input is numbers." << endl;
            cout << "Please Re-Enter Your Contact No. :";
            cin >> v_emergencyCon;
        }

        ofstream UserFile;
        UserFile.open("C:/Users/user/Downloads/C++/Volunteer/" + v_username + ".txt" , std::ios_base::app);

        UserFile << v_fname << ";" << v_lname << ";" << v_age << ";" << v_gender<< ";" <<  v_contact << ";" << v_email
            << ";" << v_address << ";" << v_emergencyName << ";" << v_emergencyRel<< ";" << v_emergencyCon;

        UserFile.close();
    }

};




int main(){
  Vol A;
  A.registerUser();
  //A.takePasswdFromUser();

}

