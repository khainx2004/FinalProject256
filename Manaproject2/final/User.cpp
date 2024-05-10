#include "User.h"

User::User()
    : name{"Unknown"} {

    }
User::User(std::string name_val) 
    : name{name_val} {

    }
void User::setname(const std::string& name_val) {
    name = name_val;
}

std::string User::getname() {
    return name;
}