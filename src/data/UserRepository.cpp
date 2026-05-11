
#include "UserRepository.h"
void UserRepository::saveUser(User& user) {
    std::ofstream file_out("user_data.dat", std::ios::binary | std::ios::app);
    if (!file_out.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    file_out.write(reinterpret_cast<char*>(&user), sizeof(user));//writing data
    file_out.close();
}

User UserRepository::findUser(const char* UN) {
    if (UN == nullptr || UN[0] == '\0') {
        throw std::invalid_argument("Invalid username");
    }
    std::ifstream file_in("user_data.dat", std::ios::binary);
    if (!file_in.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    User temp; //temporary object for reading
    while (file_in.read(reinterpret_cast<char*>(&temp), sizeof(User)))
        //read till the end of the file
        {if (std::strcmp(temp.getUser().c_str(), UN) == 0)
            //srtcmp() compares 2 strings (in this case the one from the file and the argument, == 0 means success)
            {
            return temp;  //go through the file until find certain name then return the obj
        } //strcmp compare the strings
    }
    throw std::runtime_error("Username not found");
}

void UserRepository::deleteUser(const char* UN) {

}

void UserRepository::updateUser(User& user) {

}