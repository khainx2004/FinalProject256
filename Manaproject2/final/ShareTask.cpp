#include "ShareTask.h"
ShareTask::ShareTask()
    : Task() {

    }
ShareTask::ShareTask(const std::string& name, const std::string& descript) 
    : Task(name), description(descript){

    }

std::string ShareTask::getdes() {
    return description;
}

void ShareTask::displayDetails() {
    std::cout << "ID: " << getID() << ", Share Task: " << description << " (Assigned to: ";
    if (assignedStaff.empty()) {
        std::cout << "None) ";
    }
    else {
        
        for (size_t i = 0; i < assignedStaff.size(); i++) {
            std::cout << (i == 0 ? "":", ") << assignedStaff[i]->getname() << " "; 
            
        }
    }
    std::cout << ")" << (isComplete() ? "[Completed]" : "[Pending]") << std::endl;
}

bool ShareTask::assignStaff(Staff* staff) {
    if(staff->assignTask(this) == true) {
        assignedStaff.push_back(staff);
        return true;
    }
    else {
        return false;
    }
    
}
