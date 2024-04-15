#include "Staff.h"

Staff::Staff()
    : User() {

    }
Staff::Staff(const std::string &name)
    : User(name) {

    }
void Staff::displayUserInfo() const {
    std::cout << "Staff Name: " << this->getName() << ", ID: " << this->getID() << std::endl;
}
std::vector<Task*> Staff::getAssignedTasks() const {
    return assignedTasks;
}
bool Staff::assignTask(User *user, Task *task) {
    std::cout << "Staff cannot assign tasks." << std::endl;
    return false;
}
void Staff::markTaskDone(Task* task) {
       // Find the task in the assigned tasks and mark it as done
       for (Task* assignedTask : assignedTasks) {
           if (assignedTask->getTaskName() == task->getTaskName()) {
               std::cout << "Task '" << task->getTaskName() << "' is marked as done by Staff member '" << getName() << "'" << std::endl;
               // Perform any other necessary actions, such as removing the task from the assigned tasks list
               return;
           }
       }
       std::cout << "Task '" << task->getTaskName() << "' is not assigned to Staff member '" << getName() << "'" << std::endl;
   }
