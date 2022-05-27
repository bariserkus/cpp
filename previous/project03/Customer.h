//
// Created by bariserkus on 08-Feb-22.
//

#ifndef PROJECT03_CUSTOMER_H
#define PROJECT03_CUSTOMER_H

#include "User.h"


class Customer : public User {
public:
    Customer();
    Customer(const std::string &name, const std::string &username, const std::string &email, int age);
    ~Customer();
    virtual void temp() {}
};


#endif //PROJECT03_CUSTOMER_H
