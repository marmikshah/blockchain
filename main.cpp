#include <iostream>

#include "blockchain.hpp"

int main() {
  Blockchain chain;
  chain.createGenesisBlock();
  while (1) {
    Block block = chain.mineBlock();
    chain.validateBlock(block);
    chain.adjustDifficulty();
  }

  return 0;
}
