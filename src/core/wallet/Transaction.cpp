#include "Transaction.h"

#include "Transaction.h"

void Transaction::setCurrentDate() {
    std::time_t now = std::time(nullptr);
    std::tm* t = std::localtime(&now);
    std::strftime(operationDate, sizeof(operationDate), "%d.%m.%y %H:%M", t);
}