#include "sharetask.h"

ShareTask::ShareTask()
    : Task() {}

ShareTask::ShareTask(const string& name, const string& description, const string& type, const bool& status) 
    : Task(name, description, "Share", false) {}

// ShareTask::~ShareTask() {}

void ShareTask::displayTaskDetails() 
{
    cout << "========================================" << endl;
    cout << ">>          TASK INFORMATION          <<" << endl;
    cout << "Task ID: \t\t" << getTaskId() << endl;
    cout << "Task Name: \t\t" << getTaskName() << endl;
    cout << "Description: \t\t" << getDescription() << endl;
    cout << "Task Type: \t\t" << getType() << endl; 
    cout << "Status: \t\t" << (getTaskStatus() ? "Completed" : "Incompleted") << endl;
    cout << "Name Of Assigned Staff: ";
    if (assignedStaff.empty()) {
        cout << "NONE" << std::endl;
    }
    else {
        for (int i = 0; i < assignedStaff.size(); i++) {
            cout << (i==0 ? "":", ") << assignedStaff[i]->getName() << " ";
        }
    }
    cout << "\n========================================" << endl;

}
bool ShareTask::assignStaff(Staff* staff) {
    if (staff->assignTask(this) == true) {
        assignedStaff.push_back(staff);
        return true;
    }
    else {
        return false;
    }
}