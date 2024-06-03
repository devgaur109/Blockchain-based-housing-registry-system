COMMANDS TO RUN THE CODE IN UBUNTU:
g++ -o blockchain_app.out basic_methods.cpp create_transaction.cpp NVADC.cpp sha_prog.cpp -lcrypto
./blockchain_app.out


**Decentralize House Registry Process Using Blockchain Technology in C++**

1) Our project aims to create a blockchain in which all housing related transactions of a certain society can be stored, verified and viewed.
2) The code is applicable for only one level of transaction.
3) The sample database contains data for 5 people, namely Naman, Vivek , Aadarsh, Dev, Chinmay. (data can be added as per requirement).
4) The sample society contains only 100 plots numbered from 1 to 100 respectively. (data can be added as per requirement).
5) Each sample house is worth 1000 bucks and each person has been given initially 10,000 bucks in his/her wallet.
6) The code consists of majorly 4 sub-divisions. Enter the corresponding index number for each division.- 
   - New Transaction 
   - View Block
   - Verify
   - End Program
      
> Sample Unique ids for each User - 
- Naman  16
- Vivek  22
- Aadarsh  25
- Dev  31 
- Chinmay  37

> Note:
- SHA 256 is used as Hashing Algorithm.
- The block addition requires computation of 1st five bits of hash value to be zero.

**To Run the program**
1. Clone the Repository
2. In Linux, compile using g++ *.cpp

# Authors
   1. Naman 
   2. Vivek
   3. Aadarsh
   4. Dev
   5. Chinmay
