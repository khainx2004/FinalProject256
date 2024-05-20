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
    string deadline;               // Deadline of task
    bool taskStatus;               // Completed or Incompleted
protected:
    static int taskIdCounter;      // Use for taskId

public:
    Task();
    Task(const string& name, const string& deadline);
    // ~Task();
    int getTaskId();
    string getTaskName();
    string getDealine();
    bool getTaskStatus();

    void setTaskId(int id);
    void setTaskName(string name);
    void setDeadline(string deadline);
    void setTaskStatus();
    void setAssignedUsername(string name);

    virtual void displayTaskInfo() = 0;   // Display the information of the task

};