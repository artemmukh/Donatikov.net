#pragma once
#include <string>
#include <ctime>
#include "core\auth\User.h"

enum class TransactionType {
    //using enum instead of char[] saves space (4 bytes vs 32 bytes)
    //and makes comparisons cleaner, no strcmp needed
    TopUp,
    GamePurchase,
    Subscription,
    MobileTopUp,
    MoneySend
};


class Transaction {
public:
    int id{0};//transacrion
    int userId{0}; //user id for searching in repository .dat
    TransactionType type{0}; //type of it: top-up or subscription
    double amount{0}; //money amount
    std::string description; //description of the operation
    char operationDate[15]{};   //date of operation


    void setCurrentDate();
};
//class will handle the input from the user in the qt interface
//when data is entered fully it will be converted to structs and passed to the appropriate functions and classes

//example


//Transaction t;
//t.id = ...;
//t.userId = user_obj.id;
//t.type = TransactionType::TopUp;
//t.amount = 50.0;
//t.description = "Wallet top-up";
//t.date = "2026-05-03 12:37";