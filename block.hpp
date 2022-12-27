#include <iostream>
#include <vector>
#include <stdint.h>
#include "transaction.hpp"
#include "crypto.hpp"

class Block {
 public:
  std::string getCurrentHash() { return this->currentHash; }
  std::string getPreviousHash() { return this->previousHash; }
  void setPreviousHash(std::string hash) { this->previousHash = hash; }

  /**
   * Current block's hash cannot be set but instead
   * has to be calculated at runtime.
   */
  std::string calculateBlockHash(int index, int timestamp) {
    
    std::string data = std::to_string(index) + std::to_string(timestamp);
    if (this->previousHash.length() > 0) {
      data += this->previousHash;
    }
    // TODO: Add all transactions hash

    std::cout<<"Computing SHA265 for: "<<data<<std::endl;
    return calculateSHA265(data);
  }


 private:
  std::string currentHash;
  std::string previousHash;
  std::vector<Transaction> transactions;

  uint32_t timestamp;
  uint32_t nonce;
};