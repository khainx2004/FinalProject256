#include "Task.h"
int Task::idCounter =0;

Task::Task() 
    : name{"Unknown"},complete{false} {
        id = idCounter++;
    }
Task::Task(const std::string& name)
    : name{name}, complete{false} {
        id = idCounter++;
    }
void Task::markComplete(){
    this->complete = true;
    std::cout << "Task: " << id << " marked as completed. \n";
}
bool Task::isComplete(){
    return complete;
}
int Task::getID() {
    return id;
}