#pragma once
#include <string>
#include <ctime>
#include "core\auth\User.h"
#include <stdexcept>
#include <cstring>


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
    int user_id{000};
    char username[17]{}; //user id (login) for searching in repository .dat
    TransactionType type{}; //type of it: top-up or subscription
    double amount{0}; //money amount
    char description[64]{}; //description of the operation
    char operationDate[15]{};   //date of operation


    void setUsername(const char* U);
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