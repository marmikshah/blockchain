#include <iostream>
#include "crypto.hpp"
#include <chrono>
#include "transaction.hpp"

Transaction::Transaction(std::string senderAddress, std::string receiverAddress) {
    this->senderAddress = senderAddress;
    this->receiverAddress = receiverAddress;

    const auto now = std::chrono::system_clock::now().time_since_epoch();
    
    unsigned long epoch = now / std::chrono::milliseconds(1);

    this->hash = calculateSHA265(std::to_string(epoch) + this->receiverAddress + this->senderAddress);
    
    std::cout<<"Transaction Hash: "<<this->hash<<std::endl;
} 
