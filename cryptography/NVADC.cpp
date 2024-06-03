#include <iostream>
#include <vector>
#include <string>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#include "header/create_transaction.h"
#include "header/basic_methods.h"

using namespace std;

// --- Global Definitions ---
vector<string> users { "Naman", "Vivek", "Aadarsh", "Dev", "Chinmay" };
vector<long long int> y { 65536, 97215, 78217, 9438, 4458 };
vector<int> wallet { 10000, 10000, 10000, 10000, 10000 };
int plotnumber[101];

string generateRandomKey(int size) {
    vector<unsigned char> key(size);
    if (!RAND_bytes(key.data(), size)) {
        cerr << "Error generating random key" << endl;
        return "";
    }
    return string(key.begin(), key.end());
}

vector<unsigned char> generateHMAC(const string& data, const string& key) {
    vector<unsigned char> hmacResult(EVP_MAX_MD_SIZE);
    unsigned int resultLength = 0;

    HMAC_CTX* ctx = HMAC_CTX_new();
    const EVP_MD* type = EVP_sha256();
    HMAC_Init_ex(ctx, reinterpret_cast<const unsigned char*>(key.c_str()), key.size(), type, NULL);
    HMAC_Update(ctx, reinterpret_cast<const unsigned char*>(data.c_str()), data.size());
    HMAC_Final(ctx, hmacResult.data(), &resultLength);

    HMAC_CTX_free(ctx);
    hmacResult.resize(resultLength);
    return hmacResult;
}

bool verifyTransaction(const string& transactionData, const string& key) {
    vector<unsigned char> computedHmac = generateHMAC(transactionData, key);
    return !computedHmac.empty();  // Simplified check for demonstration
}

void viewUserInfo(const vector<string>& users, const vector<int>& wallet) {
    cout << "------------------- User Information -------------------" << endl;
    for (size_t i = 0; i < users.size(); i++) {
        cout << "User: " << users[i] << ", Wallet Balance: " << wallet[i] << " bucks" << endl;
    }
}

int main() {
    createGenesis();
    string hmacKey = generateRandomKey(32);  // Generates a 32-byte random key

    while (true) {
        int n = askFunctionality();

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        if (n == 1) {
            int user_index = transactionCreate(users, y);
            string transactionData = "Sample data for transaction";  // Replace with actual data
            if (verifyTransaction(transactionData, hmacKey)) {
                transaction(user_index, users, wallet, plotnumber);
                cout << "Transaction Verified and Completed" << endl;
            } else {
                cout << "Transaction Verification Failed" << endl;
            }
        } else if (n == 2) {
            display();
        } else if (n == 3) {
            int m = verify_bc();
            if (m == 2)
                cout << "Block Chain Verified" << endl;
            else
                cout << "Block Chain Not Verified" << endl;
        } else if (n == 4) {
            viewUserInfo(users, wallet);
        } else if (n == 5) {
            return 0;
        } else {
            cout << "Enter Valid Choice" << endl;
        }
    }

    return 0;
}

