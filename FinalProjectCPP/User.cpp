#include "User.h"
#include "Task.h"

int User::idCounter = 0;
User::User()
    : name{"Unnamed User"}{
        id = NULL;
    }
User::User(const std::string &name) 
    : name{name} {
        id = ++idCounter;
    }
int User::getID() const {
    return id;
}

std::string User::getName() const {
    return name;
}


