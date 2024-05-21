#pragma once
#include "task.h"
#include "staff.h"

class SingleTask: public Task
{
private:
    Staff* assignedstaff;

public:
    SingleTask();
    SingleTask(const string& name, const string& description, const string& type, const bool& status);
    // ~SingleTask();

    void displayTaskDetails() override;
    bool assignStaff(Staff* staff);
};