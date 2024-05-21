#include "staff.h"
int Staff::staffIdCounter = 0;

Staff::Staff() : User() 
{
    staffId = ++staffIdCounter;
}

Staff::Staff(const string& name, const string& password)
    : User(name, "Staff", password) 
{
    staffId = ++staffIdCounter;
}

Staff::~Staff() {
    for (Task* task: assignedTask) {
        delete task;
    }
}

int Staff::getID(){
    return staffId;
}
const vector<Task*>& Staff::getAssignedTask() const {
    return assignedTask;
}

void Staff::displayUserInfo()
{
    cout << "========================================" << endl;
    cout << ">>          USER INFORMATION          <<" << endl;
    cout << "User ID: " << this->getID() << endl;
    cout << "User Name: " << this->getName() << endl;
    cout << "Role: " << this->getRole() << endl;
    cout << "========================================" << endl;
}


void Staff::staffMenu()
{
    int option;
    do{
        cout << "========================================" << endl;
        cout << ">>             STAFF MENU             <<" << endl;
        cout << "1. Display Staff Information" << endl;
        cout << "2. Display My Tasks List" << endl;
        cout << "3. Mark Task Done" << endl;
        cout << "4. Log Out" << endl;
        cout << "========================================" << endl;
        cout << "Enter Your Option: ";
        wcin >> option;
        cin.ignore();
        cin.clear();

        switch (option){
            case 1:
                displayUserInfo();
                break;
            case 2:
                myAssignedTask();
                break;
            case 3:
                markTaskDone();
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

void Staff::myAssignedTask()
{
    if (assignedTask.empty()) {
        cout << "!!!         NO TASK ASSIGNED         !!!" << endl;
        cout << "========================================" << endl;
    }
    else {
        cout << "========================================" << endl;
        cout << ">>          MY ASSIGNED TASKS           <<" << endl;
        for (Task* task: assignedTask) {
            task->displayTaskDetails();
        }
        cout << "========================================" << endl;
    }
}

void Staff::markTaskDone()
{
    if (assignedTask.empty()){
        cout << "!!!         NO TASK ASSIGNED         !!!" << endl;
    }
    else{
        int id;
        bool taskFound = false;
        cout << "========================================" << endl;
        cout << ">>           TASK'S STATUS            <<" << endl;
        cout << "Enter Task ID To Mark: ";
        cin >> id;
        cin.ignore();
        cin.clear();
        for (Task* task: assignedTask) {
            if (task->getTaskId() == id) {
                task->setTaskStatus();
                cout << "!!!  MARK TASK COMPLETE SUCCESSFULY  !!!" << endl;
                cout << "========================================" << endl;
                taskFound = true;
                break;
            }
        }
        if (!taskFound) {
            cout << "!!!        NOT FOUND TASK ID         !!!"<< endl;
            cout << "========================================" << endl;
        }
    }   
}

bool Staff::assignTask(Task* task) {
    if (assignedTask.empty()) {
        assignedTask.push_back(task);
        return true;
    }
    else {
        for(int i = 0; i < assignedTask.size(); i++) {
            if (assignedTask[i]->getTaskId() == task->getTaskId()) {
                return false;
            }
        }
        assignedTask.push_back(task);
        return true;
    }
}