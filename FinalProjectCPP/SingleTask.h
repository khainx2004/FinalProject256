#pragma once
#include "Task.h"
class SingleTask: public Task 
{
public: 
    SingleTask();
    SingleTask(const std::string &name);
    virtual void executeTask() override;
    virtual bool isAssignedTo(User* user) const override;
};

