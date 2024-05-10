#pragma once
#include "Task.h"
#include "Staff.h"

class ShareTask: public Task{
private:
    std::string description;
    std::vector<Staff*> assignedStaff;
public:
    ShareTask();
    ShareTask(const std::string& name, const std::string& descript);
    std::string getdes();
    void displayDetails() override;
    bool assignStaff(Staff* staff);
};