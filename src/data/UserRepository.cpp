//
// Created by user on 05.05.2026.
//

#include "UserRepository.h"
void UserRepository::saveUser(User& user) {
    std::ofstream file_out("user_data.dat", std::ios::binary | std::ios::app);
    if (!file_out.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    file_out.write(reinterpret_cast<char*>(&user), sizeof(user));//writing data
    file_out.close();
}

User UserRepository::findUser(const char* name) {
    if (name == nullptr || name[0] == '\0') {
        throw std::invalid_argument("Invalid name");
    }
    std::ifstream file_in("user_data.dat", std::ios::binary);
    if (!file_in.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    User temp; //temporary object for reading
    while (file_in.read(reinterpret_cast<char*>(&temp), sizeof(User)))
        //read till the end of the file
        {if (std::strcmp(temp.getName().c_str(), name) == 0) {
            return temp;  //go through the file until find certain name then return the obj
        } //strcmp compare the strings
    }
    throw std::runtime_error("User not found");
}
