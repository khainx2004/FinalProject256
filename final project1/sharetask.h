#pragma once
#include "task.h"
#include "staff.h"

class ShareTask: public Task{
private:
    vector<Staff*> assignedStaff;
public:
    ShareTask();
    ShareTask(const string& name, const string& description, const string& type, const bool& status);
    // ~ShareTask();

    void displayTaskDetails() override;
    bool assignStaff(Staff* staff);
};