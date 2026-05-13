
#include "TransactionRepository.h"
#include <fstream>

bool TransactionRepository::saveTransaction(Transaction &user_t) {
    std::ofstream file("transaction_data.dat", std::ios::ate | std::ios::binary | std::ios::app);
    if (!file.is_open()) {
        throw std::invalid_argument("Failed to open file");
    }
    int t_counter = static_cast<int>(file.tellp() / static_cast<std::streampos>(sizeof(Transaction)));
    file.clear();
    file.seekp(0, std::ios::beg);
    user_t.id =  t_counter + 1;
    file.write(reinterpret_cast<char*>(&user_t), sizeof(Transaction));
    file.flush();
    file.close();
}

Transaction TransactionRepository::findTransaction(int transaction_id) {
    std::ifstream file("transaction_data.dat", std::ios::ate | std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("Failed to open file");
    }

    if (file.tellg() == 0) {
        throw std::invalid_argument ("Empty file.");
    }
    file.clear();
    Transaction user_t;
    file.seekg(0, std::ios::beg);
    while (file.read(reinterpret_cast<char*>(&user_t), sizeof(Transaction))) {
        if (user_t.id == transaction_id) {
            file.close();
            return user_t;
        }

    }
    file.close();
    throw std::invalid_argument("invalid id");
}

bool TransactionRepository::deleteTransaction(int transaction_id) {
    std::fstream file("transaction_data.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("Failed to open file");
    }

    if (file.tellg() == 0) {
        throw std::invalid_argument ("Empty file.");
    }
    file.clear();
    Transaction user_t;
    file.seekg(0, std::ios::beg);
    while (file.read(reinterpret_cast<char*>(&user_t), sizeof(User))) {
        if (user_t.id == transaction_id) {
            file.seekp(static_cast<std::streamoff>(transaction_id - 1) * sizeof(User), std::ios::beg);
            user_t = Transaction();
            file.write(reinterpret_cast<char *>(&user_t), sizeof(User));
            file.flush();
            file.close();
            return true;
        }
    }
    file.close();
    throw std::invalid_argument("invalid id");
}



std::vector<Transaction> TransactionRepository::getUserTransactions(int user_ID) {
    std::ifstream file("transaction_data.dat", std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open database file.");
    }
    std::vector<Transaction> user_history;
    Transaction temp_record;

    //read the file from beg to the end
    while (file.read(reinterpret_cast<char*>(&temp_record), sizeof(Transaction))) {
        //if the id matches, push a copy into our vector
        if (temp_record.user_id == user_ID) {
            user_history.push_back(temp_record);//add to the end the transac obj of user
        }
    }
    file.close();
    if (user_history.empty()) {
        throw std::invalid_argument("Nothing was found");
    }
    return user_history;//return the vector of transaction objects belong to a single user
}


