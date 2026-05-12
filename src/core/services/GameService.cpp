#include "GameService.h"

GameService::GameService(std::string name, double price): IService(std::move(name), price) {
    setName(name);
    setPrice(price);
}

std::string GameService::printInfo() const {
    return "Game Service Name: " + getName() + "\n" +
        "Game Service Price: " + std::to_string(getPrice());
};
void GameService::execute(User &user) {
    if (user.getBalance() < getPrice()) {
        throw std::invalid_argument("Insufficient funds");
    }
    user.setBalance(user.getBalance() - getPrice());

    Transaction t_game; //creating transaction object to write data to the transaction repository
    t_game.id = 0;
    t_game.user_id = user.getId();
    t_game.setUsername(user.getUser().c_str());
    //we write (copy) from user::username to transaction::username to write to transaction file

    t_game.type = TransactionType::GamePurchase;
    t_game.amount = getPrice();

    //snprintf formats phone number into t_mobile.description
    //sizeof ensures we never write past the buffer size
    //c.str (string to const char*)

    std::snprintf(t_game.description, sizeof(t_game.description),
        "Game Service wallet top-up - %s", getName().c_str()); //this writes the information about transaction

    t_game.setCurrentDate();

    //TransactionRepository repo;
    //repo.save(t);
}
