
#include "MoneySend.h"


MoneySend::MoneySend(std::string Name, double Price, unsigned long long rcn):
IService(std::move(Name), Price)
{
    setRecipientCardNumber(rcn);
}

void MoneySend::setRecipientCardNumber(unsigned long long card) {
    if (card < 1000000000000000ULL || card > 9999999999999999ULL) {
        throw std::invalid_argument("Invalid card number");
    }
    this->recipient_card_number= card;
}

unsigned long long MoneySend::getRecipientCardNumber() const {
    return recipient_card_number;
}

std::string MoneySend::printInfo() const {
    return "";
}

void MoneySend::execute(User &user) const {}