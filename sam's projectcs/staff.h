#pragma once
#include "user.h"

class Staff : public User
{
private:
    std::vector<Task*> assignedTask;
    int ID;
protected:
    static int idCounter;
public:
    Staff();
    Staff(const string& name, const string& password);
    int getID();
    const std::vector<Task*>& getAssignedTask() const;
    void displayUserInfo() override;          // Override from User class
    void displayAssignedTask();
    void staffMenu();   // Display Menu for Staff after Sign in

    void myAssignedTask();   // Display the list of tasks that Staff uers has to complete
    void markTaskDone();     // Mark the task as Complete or Incomplete
    bool assignTask(Task* task);

};