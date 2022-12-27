#include <vector>
#include <iostream>
#include <stdexcept>
#include "block.hpp"
#include "blockchain.hpp"


void Blockchain::createGenesisBlock() {
    if(this->chain.size() != 0) {
        std::cout<<"Blockchain already initialised. Cannot create a new genesis block";
        return;
    }
}

    
void Blockchain::mineBlock() {
    while(1) {
        
    }
}

bool Blockchain::isValidChain() {
    for(int i=1;i<this->chain.size();i++){
        if (this->chain[i-1].getCurrentHash() != this->chain[i].getPreviousHash()){
            return false;
        }
    }
    return true;
}

void Blockchain::loadChain() {
    if(this->chain.size() != 0) {
        throw std::runtime_error("Attempting to re-initialise blockchain.");
    }
}