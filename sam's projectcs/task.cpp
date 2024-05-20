#include "task.h"

int Task::taskIdCounter = 0;

Task::Task() : taskName("Unnamed Task"),taskStatus{false} {
    taskId = taskIdCounter++;
}

Task::Task(const string& name, const string& deadline) 
    : taskName(name), deadline(deadline), taskStatus(false)
{
    taskId = taskIdCounter++;
}

// Task::~Task(){
    
// }
int Task::getTaskId()
{
    return this->taskId;
}

string Task::getTaskName()
{
    return this->taskName;
}

string Task::getDealine()
{
    return this->deadline;
}

bool Task::getTaskStatus()
{
    return this->taskStatus;
}

string Task::getAssignedUserName()
{
    return this->assignedUserName;
}


void Task::setTaskId(int id)
{
    this->taskId = id;
}

void Task::setTaskName(string name)
{
    this->taskName = name;
}

void Task::setDeadline(string deadline)
{
    this->deadline = deadline;
}

void Task::setTaskStatus()
{
    this->taskStatus = true;
    std::cout << "\n----------Task: " << taskId << " marked as completed.----------\n";
}

void Task::setAssignedUsername(string name)
{
    this->assignedUserName = name;
}

// void Task::displayTaskInfo() const
// {
//     cout << "---------Task Information-----------" << endl;
//     cout << "Task ID: \t\t" << this->taskId << endl;
//     cout << "Task Name: \t\t" << this->taskName << endl;
//     cout << "Deadline: \t\t" << this->deadline << endl;
//     cout << "Status: \t\t" << (this->taskStatus ? "Completed" : "Incompleted") << endl;
//     cout << "Name of assigned staff: " << this->assignedUserName << endl;
//     cout << "------------------------------------" << endl;
// }
