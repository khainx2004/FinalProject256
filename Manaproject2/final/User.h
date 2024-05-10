#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Task.h"

class User{
private:
    std::string name;
public:
    User();
    User(std::string name_val);
    void setname(const std::string& name_val);
    std::string getname();
    virtual void displayMenu() = 0;
};