#include "GameService.h"

GameService::GameService(std::string name, double price): IService(std::move(name), price) {
    setName(name);
    setPrice(price);
}

std::string GameService::printInfo() const {
    return "";
};
void GameService::execute(User &user) const {};
