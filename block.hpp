#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <stdint.h>

#include <iostream>
#include <vector>

#include "crypto.hpp"
#include "transaction.hpp"

class Block {
 public:
  Block(std::string previousHash);

  std::string getCurrentHash();
  std::string getPreviousHash();

  std::string calculateBlockHash(int nonce, unsigned long timestamp,
                                 std::string merkleRoot);

  /**
   * @brief When miner finds the correct hash, finalizeBlock
   * can be called to set the hash, nonce and timestamp values
   * that were used to generated the hash.
   */
  void finalizeBlock(std::string hash, int nonce, unsigned long timestamp,
                     std::vector<Transaction> transactions,
                     std::string merkleRoot);

 private:
  int nonce;
  unsigned long timestamp;

  std::string currentHash;
  std::string previousHash;
  std::string merkleRoot;
  std::vector<Transaction> transactions;
};

#endif