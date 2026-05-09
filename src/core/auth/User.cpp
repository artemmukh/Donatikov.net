
#include "User.h"


User:: User(int ID, const char* Name, const char* Password, double Balance):User() {
    this->setId(ID);
    this->setName(Name);
    this->setPassword(Password);
}

//setters implementation
void User::setId(int ID) {
    if (ID < 0 || ID > 999) {
        throw std::invalid_argument("Invalid ID, must be 0-999");
    }
    this->id = ID;
}

void User::setName(const char* N) {
    if (N == nullptr || N[0] == '\0') { //if nothing entered
        throw std::invalid_argument("Invalid or empty name");
    }
    if (std::strlen(N) >= sizeof(name)) { //if name is out of bonds
        throw std::invalid_argument("Name is too long");
    }
    std::size_t i = 0;
    for (; i < sizeof(name) - 1 && N[i] != '\0'; ++i) {
        name[i] = N[i];
    }
    name[i] = '\0'; //this writing stops at the length of the name 
}

void User::setPassword(const char* P) {
    if (P == nullptr || P[0] == '\0') {
        throw std::invalid_argument("Invalid or empty password");
    }
    std::size_t i = 0;
    for (; i < sizeof(password)-1 && P[i] != '\0'; ++i) { //writing password to the char array if successful
        this->password[i] = P[i];
    }
    this->password[i] = '\0';
}


//getter implementation

int User::getId() const {
    return id;
}

std::string User::getName() const {
    return std::string(name);
}


void User::setBalance(double Balance) {

    if (Balance < 0) {
        throw std::invalid_argument("Balance cannot be negative");
    }
    this->balance = Balance;
}



double User::getBalance() const {
    return balance;
}

