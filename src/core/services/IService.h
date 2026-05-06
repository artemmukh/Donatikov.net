#pragma once
#include <string>

class IService {
    std::string name;
    double price{0};
    public:
    IService() = default;
    IService(std::string name, double price);
    virtual ~IService() = default; //abstract base class for the services to be interacted with in ui

    void setName(std::string name);
    void setPrice(double price);

    std::string getName() const;
    double getPrice() const;

    virtual void printInfo() const = 0; //description of service
    virtual void execute() const = 0; //do top up, withdrawal etc

};