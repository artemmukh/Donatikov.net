#pragma once
#include "core/wallet/Transaction.h"
#include <vector>
class TransactionRepository {
    Transaction user_transaction;
    TransactionRepository() = default;
    ~TransactionRepository() = default;
    static bool saveTransaction(Transaction &user_t);
    Transaction findTransaction(int transaction_id);
    bool deleteTransaction(int transaction_id);
    std::vector<Transaction> getUserTransactions(int user_id);
};
