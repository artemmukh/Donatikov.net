#pragma once
#include "IService.h"

class GameService : public IService {
public:
    GameService() = default;

    explicit GameService(std::string name, double price);

    void setGameDetails(std::string name, double price);
    std::string getGameDetails() const;

    ~GameService() override = default;
    std::string printInfo() const override;
    void execute(User &user) const override;
};
