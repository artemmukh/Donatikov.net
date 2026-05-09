#pragma once
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <cstring>
#include "User.h"
class AuthManager {
    static User user; //current logged user data
    public:
    AuthManager() = default;

    static bool login(const char* name, const char* password);
    static bool registerUser(const char* name, const char* password);
    static void logout();
    static bool isLoggedIn();
};
