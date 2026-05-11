#pragma once
#include <fstream>
#include <exception>
#include "core/auth/User.h"

class UserRepository {
    public:
    UserRepository() = default;
    ~UserRepository() = default;
    static void saveUser(User& user); //writing data from widgets to the file
    static User findUser(const char* UN);//searching
    static void deleteUser(const char* UN);
    static void updateUser(User& user);
};
