#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int modInverse(int key, int mod) {
    for (int i = 1; i < mod; i++) {
        if ((key * i) % mod == 1)
            return i;
    }
    return -1;
}

string encrypt(string plaintext, int key1, int key2) {
    string ciphertext = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = 'A';
            int p = toupper(ch) - base;
            int t = (p * key1) % 26;
            int c = (t + key2) % 26;
            ciphertext += c + base;
        } else {
            ciphertext += ch;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int key1, int key2) {
    string plaintext = "";
    int inverseKey1 = modInverse(key1, 26);
    if (inverseKey1 == -1) {
        cout << "Error: Key1 has no modular inverse under modulo 26." << endl;
        return "";
    }
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = 'A';
            int c = ch - base;
            int t = (c - key2 + 26) % 26;
            int p = (t * inverseKey1) % 26;
            plaintext += p + base;
        } else {
            plaintext += ch;
        }
    }
    return plaintext;
}

int main() {
    string plaintext;
    int key1, key2;
    cout << "Enter plaintext:" << endl;
    cin >> plaintext;
    cout << "Enter key1:" << endl;
    cin >> key1;
    cout << "Enter key2:" << endl;
    cin >> key2;
    string ciphertext = encrypt(plaintext, key1, key2);
    cout << "Ciphertext: " << ciphertext << endl;
    string decryptedText = decrypt(ciphertext, key1, key2);
    cout << "Decrypted Text: " << decryptedText << endl;
    return 0;
}