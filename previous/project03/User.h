//
// Created by bariserkus on 29-Jan-22.
//

#ifndef PROJECT03_USER_H
#define PROJECT03_USER_H

#include <string>
#include <vector>


class User {
protected:
    std::string mName;
    std::string mUserName;
    std::string mEmail;
    int mAge;
    enum UserType {CUSTOMER, ADMIN};
    User::UserType mType;


public:
    User();
    User(const std::string &name, const std::string &username, const std::string &email, int age);
    virtual ~User();

    const std::string &getName() const;
    const std::string &getUserName() const;
    const std::string &getEmail() const;
    const int &getAge() const;
    const UserType &getType() const;
    const void PrintProfile() const;
    virtual void temp() = 0;

};


#endif //PROJECT03_USER_H
