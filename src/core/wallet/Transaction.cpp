#include "Transaction.h"


void Transaction::setCurrentDate() {
    std::time_t now = std::time(nullptr);
    std::tm* t = std::localtime(&now);
    std::strftime(operationDate, sizeof(operationDate), "%d.%m.%y %H:%M", t);
}

void Transaction::setUsername(const char* U) {
    if (U == nullptr || U[0] == '\0') {
        throw std::invalid_argument("Invalid or empty username");
    }
    if (std::strlen(U) >= sizeof(username)) {
        throw std::invalid_argument("Username is too long");
    }
    std::size_t i = 0;
    for (; i < sizeof(username) - 1 && U[i] != '\0'; ++i) {
        username[i] = U[i];
    }
    username[i] = '\0';
}