#include "sharetask.h"

ShareTask::ShareTask()
    : Task() {

    }
ShareTask::ShareTask(const std::string& name, const std::string& deadline) 
    : Task(name,deadline) {

    }
void ShareTask::displayTaskInfo() {
    cout << "---------Task Information-----------" << endl;
    cout << "Task ID: \t\t" << getTaskId() << endl;
    cout << "Task Name: \t\t" << getTaskName() << endl;
    cout << "Task Type: \t\tShare Task" << endl; 
    cout << "Deadline: \t\t" << getDealine() << endl;
    cout << "Status: \t\t" << (getTaskStatus() ? "Completed" : "Incompleted") << endl;
    cout << "Name of assigned staff: ";
    if (assignedStaff.empty()) {
        std::cout << "NONE" << std::endl;
    }
    else {
        for (int i = 0; i < assignedStaff.size(); i++) {
            cout << (i==0 ? "":", ") << assignedStaff[i]->getName() << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------" << endl;

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