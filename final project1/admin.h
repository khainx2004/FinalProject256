#pragma once
#include "user.h"
#include "task.h"
#include "staff.h"

class Admin : public User
{
private:
    //vector<Staff*> staffList;
    vector<Task*> taskList;
    
public:
    Admin();
    Admin(const string& name, const string& password);
    ~Admin() override;

    //const vector<Staff*>& getStaffMembers() const;

    void displayUserInfo() override;        // Override from User class
    
    void adminMenu(vector<User*>& userList);// Display Menu for Admin after Sign in
    void manageStaffMenu(vector<User *> & userList); // Display a Menu of actions with Staff 
    void manageTaskMenu(vector<User *> & userList);  // Display a Menu of actions with Task

    void displayStaffList(vector<User*>& userList);                // Display the list of Staffs
    void addStaff(vector<User*>& userList); // Add a new Staff
    void removeStaff(vector<User*>& userList);                     // Remove a Staff

    void displayTaskList();
    void addTask();                         // Add a new Task
    void removeTask();                      // Remove a Task
    void assignTask(vector<User*>& userList);                      // Assign a Task to a Staff
    bool canAssign(Staff* staff, Task* task);
};