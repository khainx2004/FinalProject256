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


void signIn(vector<User*>& userList){
    while (true){
        string name, password;
        cout << "--------------SIGN IN---------------" << endl;
        cout << "Enter user name: ";
        getline(cin, name);
        cout << "Enter password: ";
        getline(cin, password);

        for (int i = 0; i < userList.size(); i++){
            if (name == userList[i]->getName()){
                if (password == userList[i]->getPassword()){
                    cout << "--------Sign In Sucessfully!--------" << endl;
                    cout << "------------------------------------" << endl;
                    cout << "------------Hello " << userList[i]->getName() << "------------" << endl;

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
                else cout << "---Incorrect password. Try again!---" << endl;
                break;
            }
            else {
                cout << "No user" << endl;
            }
        }
        break;
    }
}

void signUp(vector<User*>& userList){
    while (true){
        string name, password, role;
        cout << "--------------SIGN UP---------------" << endl;
        cout << "Enter user name: ";
        getline(cin, name);
        cout << "Enter password: ";
        getline(cin, password);
        cout << "Enter role (Admin/Staff): ";
        getline(cin, role);

        if (role == "Admin"){
            userList.push_back(new Admin(name, password));
            cout << "----Admin Register Successfully!----" << endl;
            cout << "------------------------------------" << endl;
            signIn(userList);
        }
        else if (role == "Staff"){
            userList.push_back(new Staff(name, password));
            cout << "----Staff Register Successfully!----" << endl;
            cout << "------------------------------------" << endl;
            signIn(userList);
        }
        else{
            cout << "----Please enter Admin or Staff!----" << endl;
        }
        break;
    }
}



int main(){
    

    vector<User*> userList;
    

    int option;
    do{
        cout << "test 4" << endl;
        cout << "---Welcome to Task Management App---" << endl;
        cout << "1. Sign in" << endl;
        cout << "2. Sign up" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your option: ";
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
                cout << "-------------Exiting...-------------" << endl;
                break;
            default:
                cout << "------Invalid value. Try agaim!-----" << endl;
                break;
        }
    }
    while (option != 3);

    for (int i = 0; i < userList.size(); i++){
        if (userList[i] != NULL){
            delete userList[i];
        }
    }

    return 0;
}