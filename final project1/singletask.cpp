#include "singletask.h"

SingleTask::SingleTask() 
    : Task() {
        assignedstaff = nullptr;
    }
SingleTask::SingleTask(const string& name, const string& description, const string& type, const bool& status)
    : Task(name, description, "Single", false) 
{
    assignedstaff = nullptr;
}

void SingleTask::displayTaskDetails() 
{
    cout << "========================================" << endl;
    cout << ">>          TASK INFORMATION          <<" << endl;
    cout << "Task ID: \t\t" << getTaskId() << endl;
    cout << "Task Name: \t\t" << getTaskName() << endl;
    cout << "Description: \t\t" << getDescription() << endl;
    cout << "Task Type: \t\t" << getType() << endl; 
    cout << "Status: \t\t" << (getTaskStatus() ? "Completed" : "Incompleted") << endl;
    cout << "Name Of Assigned Staff: ";
    if (assignedstaff == nullptr) {
        cout << "NONE" << endl;
    }
    else {
        cout << assignedstaff->getName() << endl;
    }
    cout << "========================================" << endl;

}
bool SingleTask::assignStaff(Staff* staff) {
    if (assignedstaff == nullptr) {
        assignedstaff = staff;
        staff->assignTask(this);
        return true;
    }
    else {
        return false;
    }
}