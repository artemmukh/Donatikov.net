#pragma once
#include <fstream>

#include "core/auth/User.h"

class UserRepository {
    public:
    UserRepository() = default;
    static void saveUser(User user);
    static void loadUser();
    static User getUser(int id);
    static void deleteUser(int id);
    static void updateUser(User user);
};
