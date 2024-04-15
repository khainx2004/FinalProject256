#pragma once
#include "User.h"

class Staff:public User 
{
private: 
    std::vector<Task*> assignedTasks;
public:
    Staff();
    Staff(const std::string &name);
    virtual void displayUserInfo() const override;
    std::vector<Task*> getAssignedTasks() const override;
    bool assignTask(User *user,Task *task) override;
    void markTaskDone(Task* task);
};