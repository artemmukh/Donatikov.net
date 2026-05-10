#include "MobileTopUpService.h"
MobileTopUpService::MobileTopUpService ( std::string Name, double Price, int MobNum ):IService(std::move(Name), Price) {
    setName(std::move(Name));
    setMobileNumber(MobNum);

};


void MobileTopUpService::setMobileNumber(int MobNum) {
    if (MobNum < 0) {
        throw std::invalid_argument("Invalid mobile number");
    }
    mobile_number = MobNum;
}


int MobileTopUpService::getMobileNumber() const {
    return mobile_number;
}


void MobileTopUpService::execute() const {

}

QString MobileTopUpService::printInfo() const {
    return QString("Mobile number top-up: %1").arg(mobile_number);
}
