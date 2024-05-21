#include "task.h"

int Task::taskIdCounter = 0;

Task::Task() : taskName("Unnamed Task"),taskStatus{false} {
    taskId = ++taskIdCounter;
}

Task::Task(const string& name, const string& description, const string& type, const bool& status) 
    : taskName(name), description(description), type(type), taskStatus(status)
{
    taskId = ++taskIdCounter;
}

Task::~Task() {}

int Task::getTaskId() const
{
    return this->taskId;
}

string Task::getTaskName() const
{
    return this->taskName;
}

string Task::getDescription() const
{
    return this->description;
}

string Task::getType() const
{
    return this->type;
}

bool Task::getTaskStatus() const
{
    return this->taskStatus;
}

void Task::setTaskName(string name)
{
    this->taskName = name;
}

void Task::setDescription(string description)
{
    this->description = description;
}

void Task::setTaskStatus()
{
    this->taskStatus = true;
    cout << "========================================" << endl;
    cout << ">> Task: " << taskId << " marked as completed!" << endl;
    cout << "========================================" << endl;
}