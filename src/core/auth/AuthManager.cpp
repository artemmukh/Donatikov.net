
#include "AuthManager.h"

bool AuthManager::registerUser(const char *name, const char *e, const char *userName, const char *password) {
    if (name == nullptr || e == nullptr || userName == nullptr || password == nullptr
        || name[0] == '\0' || e[0] == '\0' || userName[0] == '\0' || password[0] == '\0') {
        throw std::invalid_argument("Invalid or empty arguments");
    }

    std::ifstream file_in("user_data.dat", std::ios::binary | std::ios::ate);
    if (!file_in.is_open()) {
        throw std::runtime_error("Failed to open file");
    }


    int users_counter = static_cast<int>(file_in.tellg() / static_cast<std::streampos>(sizeof(User)));
    int id =  users_counter + 1;

    file_in.seekg(0, std::ios::beg );
    User temp;

    while (file_in.read(reinterpret_cast<char*>(&temp), sizeof(User))) {
        if (std::strcmp(temp.getName().c_str(), userName) == 0) {
            throw std::invalid_argument("Username already exists");
        }
    }

    file_in.close();

    User user (userName, name, id, password, 0, e, 0);
    UserRepository::saveUser(user);

    return true;
}

//we take as a parameters the GUI input, validating they are not empty or deleted
// then we open the file, validating if it is open
// generate id in the order to the users 001, 002..
// we read the file to find if the username is taken already
// in the end we generate a new user and create a record to the user_data.dat


//in the id generator:
// tellg goes to the end and tells the position (the size of the file)
// tellg/sizeOf User show us the number of users as every user is fixed size ->
// empty file: tellg() = 0, -> 0/sizeU + 1 = 0 + 1 -> 1st user, 001 id
// second user: tellg() = ~48 -> 48/48 + 1 = 2 -> 2nd user and 002 id
// third user: tellg() = sizeF -> 96/48 + 1 = 3 -> 3nd user and 003 id


bool AuthManager::login(const char *userName, const char *p) {
    std::ifstream file_in("user_data.dat", std::ios::binary | std::ios::ate);
    if (!file_in.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    file_in.clear();//always reset errors
    file_in.seekg(0, std::ios::beg);
    User temp;
    while (file_in.read(reinterpret_cast<char*>(&temp), sizeof(User))) {
        if (std::strcmp(temp.getUser().c_str(), userName) == 0 && temp.checkPassword(p) == true) {
            this->current_user = temp;
            file_in.close();
            return true;
        }
    };

    throw std::invalid_argument("Invalid username or password");

}


void AuthManager::logout() {
    this->current_user = User();
}

