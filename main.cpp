#include <iostream>

#include "blockchain.hpp"

int main() {
  Blockchain chain;
  chain.createGenesisBlock();
  for (int i = 0; i < 3; i++) {
    Block block = chain.mineBlock(1);
    chain.validateBlock(block);
  }

  return 0;
}
