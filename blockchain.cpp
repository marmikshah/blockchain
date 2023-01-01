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
    Block block = Block("");
    const auto now = std::chrono::system_clock::now().time_since_epoch();
    unsigned long epoch = now / std::chrono::milliseconds(1);
    const int nonce = 0;
    
    std::vector<Transaction> transactions;

    block.finalizeBlock(block.calculateBlockHash(nonce, epoch, ""), nonce, epoch, transactions, "");
    this->chain.push_back(block);
}
    
Block Blockchain::mineBlock(int difficulty) {
    if (this->chain.size() == 0) {
        throw std::runtime_error("Blockchain is not initialized. Cannot mine");
    }
    const std::string previousHash = this->chain[this->chain.size() - 1].getPreviousHash();
    
    Block block = Block(previousHash);
    std::string nZeros = std::string(difficulty, '0');
    std::cout<<"Mining Block with difficulty: " << difficulty << std::endl;

    while (1) {
        /**
         * There is a chance that UINT32_MAX may be reached but
         * a valid hash has not been found yet. Therefore loop
         * until either a valid hash has been found by current
         * node or restart if another node mines a new block.
         */
        for(int nonce = 0; nonce < UINT32_MAX; nonce++) {
            const auto now = std::chrono::system_clock::now().time_since_epoch();
            unsigned long epoch = now / std::chrono::milliseconds(1);

            // TODO: Retrieve unconfirmed transactions
            std::vector<Transaction> transactions;
            // TODO: Compute Merkle Root of unconfirmed transactions
            std::string merkleRoot = "";

            std::string hash = block.calculateBlockHash(nonce, epoch, merkleRoot);
            if(hash.find(nZeros) != 0) continue;
            std::cout<<"Found a valid Hash.\nCreating Block"<<std::endl;

            block.finalizeBlock(hash.substr(), nonce, epoch, transactions, merkleRoot);
            return block;
        }
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

void Blockchain::validateBlock(Block block) {
    this->chain.push_back(block);
    std::cout<< "Reached block height: "<<this->blockHeight();
}

size_t Blockchain::blockHeight() { return this->chain.size(); }