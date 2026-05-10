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