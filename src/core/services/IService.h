#pragma once
#include <string>
#include <stdexcept>
#include "core/wallet/Transaction.h"

class User;
class IService {
    protected:
    std::string name;
    double price{0};
    public:
    IService() = default;
    explicit IService (std::string name, double price);
    virtual ~IService() = default;
    //abstract base class for the services to be interacted with in ui

    void setName(std::string name);
    void setPrice(double price);

    std::string getName() const;
    double getPrice() const;

    //pure virtual methods (abstract base class: no objects can be created)
    virtual std::string printInfo() const = 0; //description of service
    virtual void execute(User &user) = 0; //do top up, withdrawal etc

};