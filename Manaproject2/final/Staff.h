#pragma once
#include "User.h"

class Staff: public User {
private:
    // std::string name;
protected:
    std::vector<Task*> assignedTasks;
    int ID;
    static int idCounter;
public:
    
    Staff();
    Staff(const std::string& name);
    // void setname(const std::string& name);
    // std::string getname() const;
    int getID();
    void displayMenu() override;
    void viewAssignedTasks();
    void markTaskComplete();
    bool assignTask(Task* task);
    // friend class Admin;
};