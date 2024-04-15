#include "Admin.h"
#include "Staff.h"

Admin::Admin()
    : User() {

    }
Admin::Admin(const std::string &name)
    :User(name) {

    }
void Admin::displayUserInfo() const {
    std::cout << "Admin: " << this->getName() << ", ID: " << this->getID() << std::endl; 
}
std::vector<Task*> Admin::getAssignedTasks() const {
    return {}; //Admin has no assigned tasks
}
bool Admin::assignTask(User *user, Task *task) {
    Staff* staffMember = dynamic_cast<Staff*>(user);
        if (staffMember) {
            // Check if the task is already assigned to another user
            if (task->isAssignedTo(user)) {
                std::cout << "Task '" << task->getTaskName() << "' is already assigned to Staff member '" << user->getName() << "'" << std::endl;
                return false;
            } else {
                // Assign the task to the staff member
                task->getAssignedUsers().push_back(user);
                std::cout << "Assigned Task '" << task->getTaskName() << "' to Staff member '" << user->getName() << "'" << std::endl;
                return true;
            }
        } else {
            std::cout << "Only Admin can assign tasks to Staff members." << std::endl;
            return false;
        }
}