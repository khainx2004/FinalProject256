#pragma once
#include "Task.h"
#include "Staff.h"

class SingleTask: public Task{
private:
    std::string description;
    Staff* assignedStaff;
public:
    SingleTask();
    SingleTask(const std::string& name,const std::string& descript);
    std::string getdes();
    void displayDetails() override;
    bool assignStaff(Staff* staff);
};