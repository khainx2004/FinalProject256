#pragma once
#include "User.h"
#include "Task.h"
#include "Staff.h"
class Admin: public User {
private:
    std::vector<Staff*> staff;
    std::vector<Task*> tasks;
public:
    Admin();
    Admin(const std::string& name);
    const std::vector<Staff*>& getStaffMembers() const;
    virtual void displayMenu() override;
    void manageStaff();
    void manageTasks();
    void addStaff(Staff* newstaff);
    void addTask(Task* newtask);
    void removeStaff();
    void updateStaff();
    void viewTasks();
    bool assignTask(Staff* staff, Task* task);

};