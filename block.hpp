#include <iostream>
#include <vector>
#include <stdint.h>
#include "transaction.hpp"
#include "crypto.hpp"

class Block {
 public:

  Block(std::string previousHash){
    std::cout<<"Block Initialized"<<std::endl;
    this->previousHash = previousHash;
  }

  std::string getCurrentHash() { return this->currentHash; }
  std::string getPreviousHash() { return this->previousHash; }

  std::string calculateBlockHash(int nonce, unsigned long timestamp, std::string merkleRoot) {
    
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
  void finalizeBlock(std::string hash, int nonce, unsigned long timestamp, std::vector<Transaction> transactions, std::string merkleRoot){
      this->currentHash = hash;
      this->nonce = nonce;
      this->timestamp = timestamp;
      this->transactions = transactions;
      std::cout<<"Block "<<hash<<" finalized."<<std::endl;
  }

 private:
  int nonce;
  unsigned long timestamp;

  std::string currentHash;
  std::string previousHash;
  std::string merkleRoot;
  std::vector<Transaction> transactions;
};