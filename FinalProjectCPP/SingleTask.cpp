#include "SingleTask.h"
SingleTask::SingleTask()
    : Task("Unnamed Single Task") {

    }
SingleTask::SingleTask(const std::string &name) 
    : Task(name) {

    }
void SingleTask::executeTask() {
    std::cout << "Executing Single Task: " << this->getTaskName() << std::endl;
}
bool SingleTask::isAssignedTo(User* user) const {
        for (User* assignedUser : getAssignedUsers()) {
            if (assignedUser->getID() == user->getID()) {
                return true;
            }
        }
        return false;
}