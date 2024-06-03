# Blockchain-based-housing-registry-system
Blockchain based housing registry system that allows tenants to rent properties from owners with secure, verified details. Protected by SHA-256 and HMAC authentication, owners can view the rental history of their properties. The system includes features to verify and add new blocks to the blockchain.

This code is tested successfully on Ubuntu 22.04

To run this project use the following commands - 

1.) g++ -o blockchain_app.out basic_methods.cpp create_transaction.cpp NVADC.cpp sha_prog.cpp -lcrypto

2.) ./blockchain_app.out
