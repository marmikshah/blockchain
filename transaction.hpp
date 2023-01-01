#ifndef BLOCK_TRANSAC_HPP
#define BLOCK_TRANSAC_HPP

#include <iostream>
#include "crypto.hpp"
#include <chrono>

class Transaction {
    private:
        std::string hash;
        std::string senderAddress;
        std::string receiverAddress;

    public:
        Transaction(std::string senderAddress, std::string receiverAddress);
};

#endif