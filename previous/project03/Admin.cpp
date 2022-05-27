//
// Created by bariserkus on 08-Feb-22.
//

#include <iostream>
#include "Admin.h"

Admin::Admin(){
    mType = UserType::ADMIN;
}
Admin::Admin(const std::string &name, const std::string &username, const std::string &email, int age)
        : User{name, username, email, age} {
    mType = UserType::ADMIN;
}
Admin::~Admin() {}
