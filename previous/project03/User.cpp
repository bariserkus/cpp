//
// Created by bariserkus on 29-Jan-22.
//

#include "User.h"
#include <iostream>

User::User() {}
User::User(const std::string &name, const std::string &username, const std::string &email, int age)
: mName(name), mUserName(username), mEmail(email), mAge(age) {}
User::~User() {}

const std::string &User::getName() const {
    return mName;
}

const std::string &User::getUserName() const {
    return mUserName;
}

const std::string &User::getEmail() const{
    return mEmail;
}

const int &User::getAge() const {
    return mAge;
}

const User::UserType &User::getType() const {
    return mType;
}


const void User::PrintProfile() const {
    std::cout << "Name : " << getName() << "\n";
    std::cout << "User Name : " << getUserName() << "\n";
    std::cout << "Email : " << getEmail() << "\n";
    std::cout << "Age : " << getAge() << "\n";
    std::cout << "User Type : " << getType() << "\n";
}



