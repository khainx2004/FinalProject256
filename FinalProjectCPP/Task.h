#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "User.h"

class Task
{
private:
    std::string taskName;
    std::vector<User*> assignedUsers;
public:
    Task();
    Task(const std::string &name);
    virtual void executeTask() = 0;
    virtual bool isAssignedTo(User* user) const = 0;
    std::string getTaskName() const;
    std::vector<User*> getAssignedUsers() const;

};
