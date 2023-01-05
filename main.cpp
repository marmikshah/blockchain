#include <csignal>
#include <iostream>

#include "blockchain.hpp"

void terminate(int id) {
  std::cout << "exit with code" << id << std::endl;
  exit(id);
}

int main() {
  // Handle SIGINT
  signal(SIGINT, terminate);

  Blockchain chain;
  chain.createGenesisBlock();
  while (1) {
    Block block = chain.mineBlock();
    chain.validateBlock(block);
    chain.adjustDifficulty();
  }

  return 0;
}
