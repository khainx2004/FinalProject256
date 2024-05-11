#include "Staff.h"
int Staff::idCounter = 0;
Staff::Staff()
    : User() {
    ID = idCounter++;
    }

Staff::Staff(const std::string& name_val)
    : User(name_val) {
    ID = idCounter++;
    }
// void Staff::setname(const std::string& name_val) {
//     ;
// }
// std::string Staff::getname() const{
//     return this->getname();
// }
int Staff::getID() {
    return ID;
}
void Staff::displayMenu() {
    int choice;
    while (choice != 0) {
        std::cout << "\nStaff Menu (" << this->getname() << "): \n1. View Assigned Tasks\n2. Mark Task as Complete\n0. Exit\nEnter Choice: ";
        std::cin >> choice;
        if (choice == 1) {
            viewAssignedTasks();
        }
        else if (choice == 2) {
            markTaskComplete();
        }
        else if (choice == 0) {
            std::cout << "Exiting..\n";
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }    
}
void Staff::viewAssignedTasks() {
    if (assignedTasks.empty()) {
        std::cout << "No tasks assigned. \n";
    }
    else {
        std::cout << "Assigned Tasks: \n";
        for (Task* task: assignedTasks) {
            task->displayDetails();
        }
    }
}
void Staff::markTaskComplete() {
    if (assignedTasks.empty()) {
        std::cout << "No tasks assigned. \n";
    }
    else {
        std::cout << "\nEnter task's ID to mark as complete: ";
        int taskID;
        std::cin >> taskID;
        bool taskfound = false;
        for (Task* task: assignedTasks) {
            if (task->getID() == taskID) {
                task->markComplete();
                taskfound = true;
                break;
            }
            if (!taskfound) {
                std::cout << "Can't find task with ID: " << taskID << std::endl;
            }

        }
    }
}
bool Staff::assignTask(Task* task) {
    if (assignedTasks.empty()){
        assignedTasks.push_back(task);
        return true;
    }
    else {
        for (size_t i = 0; i < assignedTasks.size(); i++) {
            if (assignedTasks[i]->getID() == task->getID()) {
                return false;
            }
        }
        assignedTasks.push_back(task);
        return true;
    }


             
}