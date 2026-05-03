#pragma once
#include <string>

enum class TransactionType { //this is used for the quick access to the type of operation
    TopUp,  //used with struct interaction
    GamePurchase,
    Subscription,
    MobileTopUp
};

struct Transaction {
    int id; //transaction id
    int userId; //user id
    TransactionType type; //type of it (look to the enum)
    double amount; //money amount
    std::string description; //description of the operation
    std::string date;   //date of operation
};
//struct will handle the input from the user in the qt interface
//when data is entered fully it will be converted to structs and passed to the appropriate functions and classes

//example


//Transaction t;
//t.id = ...;
//t.userId = currentUser.id;
//t.type = TransactionType::TopUp;
//t.amount = 50.0;
//t.description = "Wallet top-up";
//t.date = "2026-05-03 12:37";