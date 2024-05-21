#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "task.h"

using namespace std;

class User
{
private:
    string name;            // Name of User
    string role;            // Admin or Staff
    string password;        // Password to log in

public:
    User();
    User(const string& name, const string& role, const string& password);
    virtual ~User();
    
    string getName() const;
    string getRole() const;
    string getPassword() const;

    void setName(string n);
    void setRole(string r);
    void setPassword(string p);

    virtual void displayUserInfo() = 0;       // Display the information of the user
    
};