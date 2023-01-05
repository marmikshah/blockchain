# Simple Blockchain

Implementation of a basic blockchain.

## Block Header

- Previous Hash: Hash of the previous block (Empty for genesis block)
- Current Hash: Hash of self.
- Merkle Root: (TODO) 
- Transactions (TODO)
- Nonce: A number used to generate the block's final hash.
- Timestamp: The unix timestamp of when the block is created. 

## Mining

Similar to BTC, this blockchain is also designed to use SHA265 algorithm.  
`mineBlock` [function](./blockchain.cpp) will continue generating hashes until a valid hash is found. 

Chain is initialized with difficult set to 5 (as 1 is too fast on modern computers). For debugging purposes you can set the starting difficulty [here](./blockchain.hpp).

### Initialise with Docker

Setup docker image
```bash
docker build . -t simple-miner
```

Start Mining
```bash
docker run -it simple-miner
```

### Initialise on Host

Installation
```bash
sudo apt install g++ libcrypto++-dev libcrypto++-doc libcrypto++-utils

git clone https://github.com/marmikshah/blockchain.git
cd blockchain/
make -j
```

Start Mining
```bash
./main.o
```


## P2P Network for multi-node mining.

WIP
