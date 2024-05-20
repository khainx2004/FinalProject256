#pragma once
#include "task.h"
#include "staff.h"

class SingleTask: public Task{
private:
    Staff* assignedstaff;
public:
    SingleTask();
    SingleTask(const string& name, const string& deadline);
    virtual void displayTaskInfo() override;
    bool assignStaff(Staff* staff);
};