#pragma once
class AuthManager {
    public:
    AuthManager() = default;

    static bool login(const char* name, const char* password);
    static bool registerUser(const char* name, const char* password);
    static void logout();
    static bool isLoggedIn();
};
