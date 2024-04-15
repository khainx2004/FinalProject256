#pragma once
#include "User.h"

class Admin: public User
{
public: 
    Admin();
    Admin(const std::string &name);
    virtual void displayUserInfo() const override;
    std::vector<Task*> getAssignedTasks() const override;
    bool assignTask(User *user, Task *task) override;
};
