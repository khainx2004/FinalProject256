#pragma once
#include <vector>
#include <iostream>
#include <string>

class Task{
private:
    std::string name;
    bool complete;
protected:
    int id;
    static int idCounter;
public:
    Task();
    Task(const std::string& name);
    virtual void displayDetails() = 0;
    void markComplete();
    bool isComplete() ;
    int getID() ;

};