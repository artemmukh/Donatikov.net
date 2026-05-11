
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
    return "Recipient Card Number: " + std::to_string(getRecipientCardNumber()) + "\n" +
        "Money to be sent: " + std::to_string(getPrice());
}

void MoneySend::execute(User &user) {
    if (user.getBalance() < getPrice()) {
        throw std::invalid_argument("Insufficient funds");
    }
    user.setBalance(user.getBalance() - getPrice());

    Transaction t_money; //creating transaction object to write data to the transaction repository
    t_money.id = 0;
    t_money.setUsername(user.getUser().c_str());

    //we write (copy) from user::username to transaction::username to write to transaction file

    t_money.type = TransactionType::MoneySend;
    t_money.amount = getPrice();

    //snprintf formats recipient card into description
    //%llu — placeholder unsigned long long
    //sizeof ensures we never write past the buffer size

    std::snprintf(t_money.description, sizeof(t_money.description),
        "Money on card - %llu", recipient_card_number); //this writes the information about transaction


    t_money.setCurrentDate();
    
    //TransactionRepository repo;
    //repo.save(t);
}