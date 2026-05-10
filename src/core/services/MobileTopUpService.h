#pragma once
#include  "IService.h"

class MobileTopUpService: public IService {
    int mobile_number{0};
    public:
    MobileTopUpService() = default;
    explicit MobileTopUpService(std::string Name, double Price, int MobNum);


    void setMobileNumber(int MobNum);
    int getMobileNumber() const;


    ~MobileTopUpService() override = default;
    std::string printInfo() const override;
    void execute(User &user) const override;
};