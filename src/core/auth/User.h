#pragma once
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <cstring>
#include "AuthManager.h"

class User {
    int id{0}; //initialization in case of errors or UB
    char name[32]{};
    char password[16]{};
    double balance{0.0};

    friend class AuthManager; //this is for password access

    public:
    //rule of 3 (if one constructor is overloaded then rest of them must be overloaded too)
    User() = default;
    //explicit to restrict conversion
    explicit User(int ID, const char* Name, const char* Password, double Balance);

    //why need to implement when we don't need to user1 = user2 it is pointless
    User(const User& other) = default;
    User& operator=(const User& other) = default;
    ~User() = default;

    //setters
    void setId(int ID);
    void setName(const char* N);
    void setPassword(const char* P);
    void setBalance(double Balance);

    //getters
    int getId() const;
    std::string getName() const;
    double getBalance() const;
    //we don't need getPassword as it not needed for writing to binary
    //and it is never displayed elsewhere
};
