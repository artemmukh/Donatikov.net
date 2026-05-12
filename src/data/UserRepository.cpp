
#include "UserRepository.h"
void UserRepository::saveUser(User& user) {
    std::ofstream file_out("user_data.dat", std::ios::binary | std::ios::app);
    if (!file_out.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    file_out.write(reinterpret_cast<char*>(&user), sizeof(user));//writing data
    file_out.flush();
    file_out.close();
}

User UserRepository::findUser(int ID) {
    std::ifstream file_in("user_data.dat", std::ios::binary | std::ios::ate);
    if (!file_in.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    if (file_in.tellg() == 0) {
        throw std::invalid_argument("Empty file");
    }
    file_in.clear();//always reset errors
    User user;
    file_in.seekg(0, std::ios::beg);//set pointer to 0 byte pos
    while (file_in.read(reinterpret_cast<char*>(&user), sizeof(User))) {
        if (user.getId() == ID) {
            file_in.close();
            return user;
        } //read through the file, compare by IDs and return found object
    }
    throw std::invalid_argument("ID not found");

}

void UserRepository::deleteUser(int id) {
    std::fstream file("user_data.dat", std::ios::in | std::ios:: out | std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    if (file.tellg() == 0) {
        throw std::invalid_argument("Empty file");
    }
    file.clear();//always reset errors
    User user;
    file.seekg(0, std::ios::beg);
    while (file.read(reinterpret_cast<char*>(&user), sizeof(User))) {
        if (user.getId() == id) {
            file.seekp(static_cast<std::streamoff>(id - 1) * sizeof(User), std::ios::beg);
            user = User();
            file.write(reinterpret_cast<char *>(&user), sizeof(User));
            file.flush();
            file.close();
            return;

            ;
        }
    }
    file.close();
    throw std::invalid_argument("ID not found");
}

User UserRepository::updateUser(User& user) {
}