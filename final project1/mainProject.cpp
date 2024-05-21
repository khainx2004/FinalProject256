#include <iostream>
#include <string>

#include "user.h"
#include "task.h"
#include "admin.h"
#include "staff.h"
#include "sharetask.h"
#include "singletask.h"

#include "user.cpp"
#include "task.cpp"
#include "admin.cpp"
#include "staff.cpp"
#include "sharetask.cpp"
#include "singletask.cpp"

void signIn(vector<User *> &userList);
void signUp(vector<User *> &userList);

int main(){
    vector<User*> userList;
    userList.push_back(new Admin("ADMIN", "12345"));
    int option;
    do{
        cout << endl;
        cout << "Test 6\n";
        cout << "========================================" << endl;
        cout << "||   Welcome to Task Management App   ||" << endl;
        cout << "========================================" << endl;
        cout << "1. Sign In" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Exit" << endl;
        cout << "========================================" << endl;
        cin >> option;
        cin.ignore();
        cin.clear();
        switch (option){
            case 1:
                signIn(userList);
                break;
            case 2:
                signUp(userList);
                break;
            case 3:
                cout << ">> Exiting. Thank You For Using The App!" << endl;
                cout << "========================================" << endl;
                break;
            default:
                cout << ">> Invalid Value. Please Try Again!" << endl;
                break;
        }
    }
    while (option != 3);

    for (User *user : userList)
    {
        delete user;
    }

    return 0;
}

void signIn(vector<User*>& userList){
    while (true){
        string name, password;
        cout << "========================================" << endl;
        cout << "||               SIGN IN              ||" << endl;
        cout << "========================================" << endl;
        cout << ">> Enter User Name: ";
        getline(cin, name);
        cout << ">> Enter Password: ";
        getline(cin, password);

        bool userFound = false;
        for (int i = 0; i < userList.size(); i++){
            if (name == userList[i]->getName()){
                if (password == userList[i]->getPassword()){
                    cout << "========================================" << endl;
                    cout << "||        SIGN IN SUCCESSFULLY        ||" << endl;
                    cout << "========================================" << endl;
                    cout << ">>      HELLO " << userList[i]->getName() << endl;
                    cout << "========================================" << endl;
                    userFound = true;
                    if (userList[i]->getRole() == "Admin"){
                        Admin* admin = dynamic_cast<Admin*> (userList[i]);
                        admin->adminMenu(userList);
                        break;
                    }
                    else if (userList[i]->getRole() == "Staff"){
                        Staff* staff = dynamic_cast<Staff*> (userList[i]);
                        staff->staffMenu();
                        break;
                    }

                }
                else{
                    cout << endl;
                    cout << "!!!  INCORRECT PASSWORD. TRY AGAIN   !!!" << endl;
                    cout << "========================================" << endl;
                    cout << endl;
                }
                break;
            }
        }
        if (!userFound){
            cout << "!!!         NOT FOUND USER          !!!" << endl;
            cout << "========================================" << endl;
        }
        break;
    }
}

void signUp(vector<User*>& userList){
    while (true){
        string name, password;
        cout << "========================================" << endl;
        cout << "||          SIGN UP FOR STAFF         ||" << endl;
        cout << "========================================" << endl;
        cout << "Enter User Name: ";
        getline(cin, name);
        cout << "Enter Password: ";
        getline(cin, password);

        bool userFound = false;
        for (int i = 0; i < userList.size(); i++){
            if (userList[i]->getName() == name){
                cout << "!!!      USER IS ALREADY EXIST       !!!" << endl;
                cout << "========================================" << endl;
                userFound = true;
            }
        }
        if (!userFound){
            //Staff* newstaff = new Staff(name,password);
            userList.push_back(new Staff(name,password));
            cout << endl;
            cout << "!!!   STAFF REGISTER SUCCESSFULLY    !!!" << endl;
            cout << "========================================" << endl;
            cout << endl;
            signIn(userList);
            break;
        }
    }
}