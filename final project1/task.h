#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task
{
private:
    int taskId;                    // ID of task
    string taskName;               // Name of task
    string description;            // Description of task
    string type;                   // Single or Share task
    bool taskStatus;               // Completed or Incompleted

protected:
    static int taskIdCounter;      // Use for taskId

public:
    Task();
    Task(const string& name, const string& description, const string& type, const bool& status);
    virtual ~Task();

    int getTaskId() const;
    string getTaskName() const;
    string getDescription() const;
    string getType() const;
    bool getTaskStatus() const;

    void setTaskName(string name);
    void setDescription(string description);
    // void setType(string type);
    void setTaskStatus();

    virtual void displayTaskDetails() = 0;   // Display the information of the task
    
};