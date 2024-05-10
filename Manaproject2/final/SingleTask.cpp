#include "SingleTask.h"

SingleTask::SingleTask()
    : Task() {
        assignedStaff = nullptr;

    }
SingleTask::SingleTask(const std::string& name,const std::string& descript) 
    : Task(name), description(descript){
        assignedStaff = nullptr;
    }

std::string SingleTask::getdes() {
    return description;
}

void SingleTask::displayDetails() {
    std::cout << "ID: " << getID() << ", Single Task: " << description << " (Assigned to: ";
    if (assignedStaff == nullptr) {
        std::cout << "None) ";
    }
    else {
        std::cout << assignedStaff->getname() << ") ";
    }
    std::cout << (isComplete() ? "[Completed]" : "[Pending]") << std::endl;
}

bool SingleTask::assignStaff(Staff* staff) {
    if (assignedStaff == nullptr) {
        assignedStaff = staff;
        staff->assignTask(this);
        return true;
    }
    else {
        std::cout << "Error: This task is already assigned to another staff member." << std::endl;
        return false;
    }
}
