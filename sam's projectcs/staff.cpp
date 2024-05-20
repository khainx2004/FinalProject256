#include "staff.h"
int Staff::idCounter = 0;

Staff::Staff() : User() {
    ID = idCounter++;
}

Staff::Staff(const string& name, const string& password)
    : User(name, "Staff", password) {
        ID = idCounter++;
    }

int Staff::getID(){
    return ID;
}
const std::vector<Task*>& Staff::getAssignedTask() const {
    return assignedTask;
}

void Staff::displayUserInfo()
{
    cout << "----------Staff Information----------" << endl;
    cout << "Staff ID: " << this->getID() << endl;
    cout << "Staff name: " << this->getName() << endl;
    cout << "------------------------------------" << endl;
}


void Staff::staffMenu()
{
    int option;
    do{
        cout << "-------------Staff Menu-------------" << endl;
        cout << "1. Display Staff Information" << endl;
        cout << "2. Display My Tasks List" << endl;
        cout << "3. Mark Task Done" << endl;
        cout << "4. Log out" << endl;
        cout << "Enter your option: ";
        cin >> option;
        cin.ignore();
        cin.clear();

        switch (option){
            case 1:
                displayUserInfo();
                break;
            case 2:
                displayAssignedTask();
                break;
            case 3:
                markTaskDone();
                break;
            case 4:
                cout << "-----------Logging out...-----------" << endl;
                break;
            default:
                cout << "-----Invalid value. Try again!------" << endl;
                break;
        }
    }
    while (option != 4);
}

void Staff::displayAssignedTask() {
    if (assignedTask.empty()) {
        std::cout << "No tasks assigned. \n";
    }
    else {
        std::cout << "--------My Assigned Tasks--------\n";
        for (Task* task: assignedTask) {
            task->displayTaskInfo();
        }
    }
}

void Staff::markTaskDone()
{
    if (assignedTask.empty()){
        cout << "---------No Tasks Assinged---------\n";
    }
    else{
        int id;
        bool taskFound = false;
        cout << "----------Task's Status-----------" << endl;
        cout << "Enter task ID to mark: ";
        cin >> id;
        cin.ignore();
        cin.clear();
        for (Task* task: assignedTask) {
            if (task->getTaskId() == id) {
                task->setTaskStatus();
                taskFound = true;
                break;
            }
            if (!taskFound) {
                cout << "Can't find task with ID: " << id << endl;
            }
        }
        cout << "------------------------------------" << endl;
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