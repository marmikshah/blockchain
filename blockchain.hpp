#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include <iostream>
#include <vector>

#include "block.hpp"

class Blockchain {
 private:
  std::vector<Block> chain;

 public:
  /**
   * Initiate a Mining Session.
   *
   * After local (node's) copy of Blockchain is initialized
   * and validated, the node can start mining for new blocks.
   *
   */
  Block mineBlock(int difficulty);

  /**
   * Validate each block by checking whether
   * hashes match.
   * @returns true if loaded blockchain is valid.
   */
  bool isValidChain();

  /**
   * Chain Initialization
   * Genesis block will be created with 0 transactions
   * The first Node in the P2P network will create
   * the genesis block and broadcast the chain to
   * all other nodes.
   */
  void createGenesisBlock();

  /**
   * For any new node, the loadChain must be
   * called to pull the blockchain definition
   * from the network.
   */
  void loadChain();

  /*
   * Validate Block
   */
  void validateBlock(Block block);

  size_t blockHeight();
};

#endif