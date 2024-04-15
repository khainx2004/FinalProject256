#pragma once
#include "Task.h"

class ShareTask: public Task
{
public:
    ShareTask();
    ShareTask(const std::string &name);
    void executeTask() override;
    virtual bool isAssignedTo(User* user) const override;
};