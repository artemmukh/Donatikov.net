
#include "User.h"


User:: User(int ID, const char* Name, const char* Password, double Balance, const char* e, unsigned long long card)
:User() {
    this->setId(ID);
    this->setName(Name);
    this->setPassword(Password);
    this->setBalance(Balance);
    this->setEmail(e);
    this->setCardNumber(card);
}


//setters implementation
void User::setId(int ID) {
    if (ID < 0 || ID > 999) {
        throw std::invalid_argument("Invalid ID, must be 0-999");
    }
    this->id = ID;
}

int User::getId() const {
    return id;
}


//name
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

std::string User::getName() const {
    return std::string(name);
}


//password
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


//email
void User::setEmail(const char *e) {
    if (e == nullptr || e[0] == '\0') {
        throw std::invalid_argument("Invalid or empty email");
    }
    std::size_t i = 0;
    for (; i < sizeof(email) - 1 && e[i] != '\0'; ++i) {
        email[i] = e[i];
    }
    email[i] = '\0';
}

std::string User::getEmail() const {
    return std::string(email);
}


//balance
void User::setBalance(double Balance) {

    if (Balance < 0) {
        throw std::invalid_argument("Balance cannot be negative");
    }
    this->balance = Balance;
}

double User::getBalance() const {
    return balance;
}


//credit card
void User::setCardNumber(unsigned long long card) {
    if (card < 1000000000000000ULL || card > 9999999999999999ULL) {
        throw std::invalid_argument("Invalid card number");
    } //checking for 16 digits card (unsigned long for 16 prior to int 10)
    this->credit_card = card;
}


std::string User::getMaskedCardNumber() const {
    unsigned long long lastFour = credit_card % 10000;  //masking card and showing last 4 digits
    return "**** **** **** " + std::to_string(lastFour);
}


//wallet managing

void User::deposit(double amount) {
    balance += amount;
}


void User::withdraw(double amount) {
    balance -= amount;
}


//data managing
void User::updateName(const char *newName) {
    setName(newName);
}

void User::updatePassword(const char *newPassword) {
    setPassword(newPassword);
}

