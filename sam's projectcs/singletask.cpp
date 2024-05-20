#include "singletask.h"

SingleTask::SingleTask() 
    : Task() {
        assignedstaff = nullptr;
    }
SingleTask::SingleTask(const string& name, const string& deadline)
    : Task(name,deadline ) {
        assignedstaff = nullptr;
}
void SingleTask::displayTaskInfo() {
    cout << "---------Task Information-----------" << endl;
    cout << "Task ID: \t\t" << getTaskId() << endl;
    cout << "Task Name: \t\t" << getTaskName() << endl;
    cout << "Task Type: \t\tSingle Task" << endl; 
    cout << "Deadline: \t\t" << getDealine() << endl;
    cout << "Status: \t\t" << (getTaskStatus() ? "Completed" : "Incompleted") << endl;
    cout << "Name of assigned staff: ";
    if (assignedstaff == nullptr) {
        std::cout << "NONE" << std::endl;
    }
    else {
        std::cout << assignedstaff->getName() << std::endl;
    }
    cout << "------------------------------------" << endl;

}
bool SingleTask::assignStaff(Staff* staff) {
    if (assignedstaff == nullptr) {
        assignedstaff = staff;
        staff->assignTask(this);
        return true;
    }
    else {
        cout << "Error: This task is already assigned to another staff member." << endl;
        return false;
    }
}