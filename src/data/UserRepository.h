#pragma once
#include <fstream>
#include <exception>
#include "core/auth/User.h"

class UserRepository {
    public:
    UserRepository() = default;
    ~UserRepository() = default;
    static void saveUser(User& user); //writing data from widgets to the file
    static User findUser(int id);//searching
    static void deleteUser(int id);
    static User updateUser(User& user);
};
