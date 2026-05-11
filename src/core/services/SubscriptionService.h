#pragma once
#include "IService.h"

class SubscriptionService: public IService{
    int subscription_duration_day{0};
    public:
    SubscriptionService() = default;
    explicit SubscriptionService(std::string Name, double Price, int SubDuration);

    void setSubscriptionDuration(int SubDuration);
    int getSubscriptionDuration() const;

    ~SubscriptionService() override = default;
    std::string printInfo() const override;
    void execute(User &user)  override;
};
