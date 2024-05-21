#include "admin.h"
#include "singletask.h"
#include "sharetask.h"

Admin::Admin() : User() {}

Admin::Admin(const string& name, const string& password)
    : User(name, "Admin", password) {}

Admin::~Admin() {
    for (Task* t: taskList) {
        delete t;
    }
}

void Admin::displayUserInfo()
{
    cout << "========================================" << endl;
    cout << "           USER INFORMATION            " << endl;
    cout << "User Name: " << this->getName() << endl;
    cout << "Role: " << this->getRole() << endl;
    cout << "========================================" << endl;
}
// const vector<Staff*>& Admin::getStaffMembers() const 
// {
//     return staffList;
// }

void Admin::adminMenu(vector<User*>& userList)
{
    int option;
    do{
        cout << "========================================" << endl;
        cout << ">>             ADMIN MENU             <<" << endl;
        cout << "1. Display User Information" << endl;
        cout << "2. Manage Staff" << endl;
        cout << "3. Manage Task" << endl;
        cout << "4. Log Out" << endl;
        cout << "========================================" << endl;
        cout << ">> Enter Your Option: ";
        cin >> option;
        cin.ignore();
        cin.clear();
        switch (option)
        {
        case 1:
            displayUserInfo();
            break;
        case 2:
            manageStaffMenu(userList);
            break;
        case 3:
            manageTaskMenu(userList);
            break;
        case 4:
            cout << endl;
            cout << "!!!          LOGGING OUT...          !!!" << endl;
            cout << endl;
            break;
        default:
            cout << endl;
            cout << "!!!     INVALID VALUE. TRY AGAIN     !!!" << endl;
            cout << endl;
            break;
        }
    }
    while (option != 4);
}

void Admin::manageStaffMenu(vector<User*>& userList)
{
    int option;
    do{
        cout << "========================================" << endl;
        cout << ">>            MANAGE STAFF            <<" << endl;
        cout << "1. Display Staff List" << endl;
        cout << "2. Add A New Staff" << endl;
        cout << "3. Remove A Staff" << endl;
        cout << "4. Back" << endl;
        cout << "========================================" << endl;
        cout << "Enter Your Option: ";
        cin >> option;
        cin.ignore();
        cin.clear();
        switch(option){
            case 1:
                displayStaffList(userList);
                break;
            case 2:
                addStaff(userList);
                break;
            case 3:
                removeStaff(userList);
                break;
            case 4:
                cout << endl;
                cout << "!!!          LOGGING OUT...          !!!" << endl;
                cout << endl;
                break;
            default:
                cout << endl;
                cout << "!!!     INVALID VALUE. TRY AGAIN     !!!" << endl;
                cout << endl;
                break;
        }
    }
    while(option != 4);
}

void Admin::manageTaskMenu(vector<User *> & userList)
{
    int option;
    do{
        cout << "========================================" << endl;
        cout << ">>            MANAGE TASK             <<" << endl;
        cout << "1. Display Task List" << endl;
        cout << "2. Add A New Task" << endl;
        cout << "3. Remove A Task" << endl;
        cout << "4. Assign Task To Staff" << endl;
        cout << "5. Back" << endl;
        cout << "========================================" << endl;
        cout << "Enter Your Option: ";
        cin >> option;
        cin.ignore();
        cin.clear();
        switch(option){
            case 1:
                displayTaskList();
                break;
            case 2:
                addTask();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                assignTask(userList);
                break;
            case 5:
                cout << endl;
                cout << "!!!          GOING BACK...          !!!" << endl;
                cout << endl;
                break;
            default:
                cout << endl;
                cout << "!!!     INVALID VALUE. TRY AGAIN     !!!" << endl;
                cout << endl;
                break;
        }
    }
    while(option != 5);
}

void Admin::displayStaffList(vector<User*>& userList)
{
    cout << "========================================" << endl;
    cout << ">>            STAFF LIST              <<" << endl;
    bool staffFound = false;
    for (int i = 0; i < userList.size(); i++){
        if (userList[i]->getRole() == "Staff"){
            Staff* staff = dynamic_cast<Staff*> (userList[i]);
            cout << i+1 << ". ID: " << staff->getID() << "\tName: " << userList[i]->getName() << endl;
            staffFound = true;
        }
    }
    if (!staffFound){
        cout << "!!!          NO STAFF FOUND          !!!" << endl;
        cout << "========================================" << endl;
    }
}

void Admin::addStaff(vector<User*>& userList)
{
    string name, password;
    cout << "========================================" << endl;
    cout << ">>        ADDING A NEW STAFF          <<" << endl;
    cout << "Enter Staff Name: ";
    getline(cin, name);
    cout << "Enter Password For Staff: ";
    getline(cin, password);

    //Staff* newstaff = new Staff(name,password);
    //staffList.push_back(newstaff);
    userList.push_back(new Staff(name,password));
    cout << "!!!    ADD NEW STAFF SUCCESSFULLY    !!!" << endl;
    cout << "========================================" << endl;

}

void Admin::removeStaff(vector<User*>& userList)
{
    string name;
    cout << "========================================" << endl;
    cout << ">>          REMOVING A STAFF          <<" << endl;
    cout << "Enter Staff's Name To Remove: ";
    getline(cin, name);
    bool staffFound = false;

    for (int i = 0; i < userList.size(); i++){
        if (userList[i]->getRole() == "Staff") {
            if (userList[i]->getName() == name){
                userList.erase(userList.begin() + i);
                cout << "!!!     REMOVE STAFF SUCCESSFULLY    !!!" << endl;
                cout << "========================================" << endl;
                staffFound = true;
            }
        }
    }
    if(!staffFound){
        cout << "!!!      CANNOT REMOVE ADMIN     !!!" << endl;
    }
}
void Admin::displayTaskList()
{
    if (taskList.empty()){
        cout << "!!!           NO TASK FOUND          !!!" << endl;
        cout << "========================================" << endl;
    }
    else{
        cout << "========================================" << endl;
        cout << ">>            TASK LIST               <<" << endl;
        for (int i = 0; i < taskList.size(); i++){
            taskList[i]->displayTaskDetails();
        }
        cout << "========================================" << endl;
    }
}

void Admin::addTask()
{
    string taskName, description, type;
    cout << "Enter Task Name: ";
    getline(cin, taskName);
    cout << "Enter Description: ";
    getline(cin, description);
    cout << "Type Of Task (Single / Share): " << endl;
    getline(cin, type);

    if (type == "Single" || type == "single" || type == "SINGLE") {
        taskList.push_back(new SingleTask(taskName, description, "Single", false));
    }
    else if (type == "Shared" || type == "shared" || type == "SHARED" || type == "Share" || type == "SHARE" || type == "share"){ 
        taskList.push_back(new ShareTask(taskName, description, "Share", false));
    }
    cout << "!!!     ADD NEW TASK SUCCESSFULLY    !!!" << endl;
    cout << "========================================" << endl;
}

void Admin::removeTask()
{
    int taskId;
    cout << "Enter Task ID To Remove: ";
    cin >> taskId;
    cin.ignore();
    cin.clear();

    for (int i = 0; i < taskList.size(); i++){
        if (taskId == taskList[i]->getTaskId()){
            taskList.erase(taskList.begin() + i);
            cout << "!!!     REMOVE TASK SUCCESSFULLY     !!!" << endl;
            cout << "========================================" << endl;
        }
    }
}

void Admin::assignTask(vector<User*>& userList)
{
    string staffName;
    int taskId;
    bool staffFound = false;
    bool taskFound = false;
    cout << "========================================" << endl;
    cout << ">>        ASSIGN TASK TO STAFF        <<" << endl;
    cout << "Enter Staff's Name To Asign: ";
    getline(cin, staffName);

    for (int i = 0; i < userList.size(); i++) {
        if (userList[i]->getName() == staffName) {
            staffFound = true;
            cout << "Enter Task'ID To Assign: ";
            cin >> taskId;
            cin.ignore();
            cin.clear();
            for (const auto& t: taskList) {
                if (t->getTaskId() == taskId) {
                    taskFound = true;
                    Staff* staff = dynamic_cast<Staff*> (userList[i]);
                    if (canAssign(staff,t) == true) {
                        cout << "!!! ASSIGNED TASK TO STAFF SUCCESSFULLY !!!" << endl;
                        cout << "========================================" << endl;
                    }
                    else {
                        cout << "!!!   THIS TASK IS ALREADY ASSIGNED    !!!" << endl;
                        cout << "========================================" << endl;
                    }
                    break;
                }
            }
            if (!taskFound) {
                cout << "!!!           NO TASK FOUND          !!!" << endl;
                cout << "========================================" << endl;
            }
            break;
        }

    }
    if (!staffFound) {
        cout << "!!!          NO STAFF FOUND          !!!" << endl;
        cout << "========================================" << endl;
    }
}

bool Admin::canAssign(Staff* staff, Task* task) {
        if (dynamic_cast<SingleTask*>(task)) {
            SingleTask* singletask = static_cast<SingleTask*>(task);
            return singletask->assignStaff(staff);
        }
        else {
            ShareTask* sharetask = static_cast<ShareTask*>(task);
            return sharetask->assignStaff(staff);
        }
}
