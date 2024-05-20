#include "user.h"


User::User() : name("Unnamed User") {}

User::User(const string& name, const string& role, const string& password)
    : name(name), role(role), password(password) {}

// User::~User(){

// }
string User::getName() const
{
    return this->name;
}

string User::getRole() const
{
    return this->role;
}

string User::getPassword() const
{
    return this->password;
}

void User::setName(string n)
{
    this->name = n;
}

void User::setRole(string r)
{
    this->role = r;
}

void User::setPassword(string p)
{
    this->password = p;
}
