//
// Created by bariserkus on 08-Feb-22.
//

#ifndef PROJECT03_ADMIN_H
#define PROJECT03_ADMIN_H

#include "User.h"


class Admin : public User {
public:
    Admin();
    Admin(const std::string &name, const std::string &username, const std::string &email, int age);
    ~Admin();
    virtual void temp() {}
};


#endif //PROJECT03_ADMIN_H
