#pragma once
#include <stdexcept>
#include <cstddef>
#include <string>
#include <cstring>
#include "User.h"
#include "data/UserRepository.h"
class AuthManager {
    User current_user; //current logged user data
    public:
    AuthManager() = default;

    bool login(const char* userName, const char* password);
    static bool registerUser(const char* name, const char* e, const char* userName, const char* password);
    void logout();
};
