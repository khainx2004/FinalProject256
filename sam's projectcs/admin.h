#pragma once
#include "user.h"
#include "task.h"
#include "staff.h"


class Admin : public User
{
private:
    std::vector<Staff*> staff;
    std::vector<Task*> taskList;
public:
    Admin();
    Admin(const string& name, const string& password);

    const std::vector<Staff*>& getStaffMembers() const;

    void displayUserInfo() override;          // Override from User class
    
    void adminMenu(vector<User*>& userList);   // Display Menu for Admin after Sign in

    void displayStaffList(); // Display the list of Staffs
    void addStaff(vector<User*>& userList);         // Add a new Staff
    void removeStaff();      // Remove a Staff

    void displayTaskList();
    void addTask();          // Add a new Task
    void removeTask();       // Remove a Task
    void assignTask();  // Assign a Task to a Staff
    bool canAssign(Staff* staff, Task* task);
};