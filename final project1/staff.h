#pragma once
#include "user.h"

class Staff : public User
{
private:
    vector<Task*> assignedTask;
    int staffId;
protected:
    static int staffIdCounter;
public:
    Staff();
    Staff(const string& name, const string& password);
    ~Staff();

    int getID();
    const vector<Task*>& getAssignedTask() const;

    void displayUserInfo() override;    // Override from User class

    void staffMenu();                   // Display Menu for Staff after Sign in
    void myAssignedTask();              // Display the list of tasks that Staff uers has to complete
    void markTaskDone();                // Mark the task as Complete or Incomplete
    bool assignTask(Task* task);

};


