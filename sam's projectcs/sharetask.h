#pragma once
#include "task.h"
#include "staff.h"

class ShareTask: public Task{
private:
    std::vector<Staff*> assignedStaff;
public:
    ShareTask();
    ShareTask(const std::string& name, const std::string& deadline);
    virtual void displayTaskInfo() override;
    bool assignStaff(Staff* staff);
};