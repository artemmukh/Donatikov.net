#include "MobileTopUpService.h"

#include <qpoint.h>

#include "core/auth/User.h"
#include "ui/aboutuswindow.h"

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


void MobileTopUpService::execute(User &user) {
    if (user.getBalance() < getPrice()) {
        throw std::invalid_argument("Insufficient funds");
    }
    user.setBalance(user.getBalance() - getPrice());

    Transaction t_mobile; //creating transaction object to write data to the transaction repository
    t_mobile.id = 0;
    t_mobile.user_id = user.getId();
    t_mobile.setUsername(user.getUser().c_str());
    //we write (copy) from user::username to transaction::username to write to transaction file
    t_mobile.status = false;
    t_mobile.type = TransactionType::MobileTopUp;
    t_mobile.amount = getPrice();

    //snprintf formats phone number into t_mobile.description
    //%d — placeholder whole number (d = decimal)
    //sizeof ensures we never write past the buffer size

    std::snprintf(t_mobile.description, sizeof(t_mobile.description),
        "Mobile Top Up - %d", mobile_number); //this writes the information about transaction

    t_mobile.setCurrentDate();

    //TransactionRepository repo;
    //repo.save(t);
}

std::string MobileTopUpService::printInfo() const {
    return "Mobile Operator Name: " + getName() + "\n" +
        "Mobile Number: " + std::to_string(getMobileNumber()) + "\n" +
            + "Amount to withdraw" + std::to_string(getPrice());
}
