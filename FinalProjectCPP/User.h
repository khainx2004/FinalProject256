#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Task.h"

class User
{
private:
    int id;
    std::string name;
protected:
    static int idCounter;
public:
    User();
    User(const std::string &name);
    virtual void displayUserInfo() const = 0;
    virtual std::vector<Task*> getAssignedTasks() const = 0;
    virtual bool assignTask(User* user, Task* task) = 0;
    int getID() const;
    std::string getName() const;

};