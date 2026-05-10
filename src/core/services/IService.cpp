#include "IService.h"
#include "core/auth/user.h"
std::string IService::getName() const {
    return name;
}

double IService::getPrice() const {
    return price;
}


IService::IService(std::string Name, double Price) {
    this->setName(std::move(Name));
    this->setPrice(Price);
}

void IService::setPrice(double Price) {
    if (Price < 0) {
        throw std::invalid_argument("Price cannot be negative");
    }
    this->price = Price;
}

void IService::setName(std::string Name) {
    if (Name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }
    if (Name.length() > 20) {
        throw std::invalid_argument("Name cannot be longer than 20 characters");
    }
    this->name = std::move(Name);
}