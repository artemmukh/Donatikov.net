#include "SubscriptionService.h"

SubscriptionService::SubscriptionService(std::string Name, double Price, int SubDuration):
IService(std::move(Name), Price){
    setSubscriptionDuration(SubDuration);
}


void SubscriptionService::setSubscriptionDuration(int SubDuration) {
    if (SubDuration < 0) {
        throw std::invalid_argument("Invalid subscription duration");
    }
    subscription_duration_day = SubDuration;
}


int SubscriptionService::getSubscriptionDuration() const {
    return subscription_duration_day;
}


std::string SubscriptionService::printInfo() const {
    return "Subscription Name: " + getName() + "\n" +
        "Subscription Price: " + std::to_string(getPrice()) + "\n" +
            "Subscription Duration: " + std::to_string(getSubscriptionDuration());
}



void SubscriptionService::execute(User &user) {
    if (user.getBalance() < getPrice()) {
        throw std::invalid_argument("Insufficient funds");
    }
    user.setBalance(user.getBalance() - getPrice());

    Transaction t_sub; //creating transaction object to write data to the transaction repository
    t_sub.id = 0;
    t_sub.setUsername(user.getUser().c_str());
    t_sub.type = TransactionType::Subscription;
    t_sub.amount = getPrice();


    //snprintf formats a string into t_sub.description
    //%s is replaced by service name, %d by duration in days

                //%s — placeholder string (s = string)
                //%d — placeholder whole number (d = decimal)


    //sizeof ensures we never write past the buffer size


    std::snprintf(t_sub.description, sizeof(t_sub.description),
        "%s - %d months", name.c_str(),
        subscription_duration_day); //this writes the inforamtion about transaction
    //"Netflix 1 months"
    t_sub.setCurrentDate();

    //TransactionRepository repo;
    //repo.save(t);
}