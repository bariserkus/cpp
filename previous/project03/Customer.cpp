//
// Created by bariserkus on 08-Feb-22.
//

#include <iostream>
#include "Customer.h"

Customer::Customer(){
    mType = UserType::CUSTOMER;
}

Customer::Customer(const std::string &name, const std::string &username, const std::string &email, int age)
: User{name, username, email, age}{
    mType = UserType::CUSTOMER;
}

Customer::~Customer() {}

