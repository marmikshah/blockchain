#include <iostream>
#include <vector>
#include <stdint.h>
#include "transaction.hpp"
#include "crypto.hpp"

class Block {
 public:
  std::string getCurrentHash() { return this->currentHash; }
  std::string getPreviousHash() { return this->previousHash; }

  std::string calculateBlockHash(int nonce, int timestamp, std::string merkleRoot) {
    
    std::string data = std::to_string(nonce) + std::to_string(timestamp);
    if (this->previousHash.length() > 0) {
      data += this->previousHash;
    }
    if(merkleRoot.length() > 0){
      data += merkleRoot;
    }

    std::cout<<"Computing SHA265 for: "<<data<<std::endl;
    return calculateSHA265(data);
  }

  /**
   * @brief When miner finds the correct hash, finalizeBlock
   * can be called to set the hash, nonce and timestamp values
   * that were used to generated the hash. 
   */
  void finalizeBlock(std::string previousHash, std::string hash, int nonce, int timestamp, std::vector<Transaction> transactions){
      this->currentHash = hash;
      this->previousHash = previousHash;
      this->nonce = nonce;
      this->timestamp = timestamp;
      this->transactions = transactions;
      std::cout<<"Block "<<hash<<" finalized."<<std::endl;
  }

 private:
  std::string currentHash;
  std::string previousHash;
  int nonce;
  int timestamp;
  std::vector<Transaction> transactions;
};