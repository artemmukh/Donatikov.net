#pragma once
#include "IService.h"

class MoneySend: public IService{
    unsigned long long recipient_card_number{0};//card is 16 letter and positive, while int is only 10 and can be < 0
    public:
    MoneySend() = default;
    explicit MoneySend(std::string Name, double Price, unsigned long long RCN);

    void setRecipientCardNumber(unsigned long long rcn);
    unsigned long long getRecipientCardNumber() const;

    ~MoneySend() override = default;
    std::string printInfo() const override;
    void execute(User &user) const override;
};
