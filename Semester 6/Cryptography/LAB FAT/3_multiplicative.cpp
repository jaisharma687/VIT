#include<bits/stdc++.h>
using namespace std;

int modInverse(int key, int mod) {
    for (int i = 1; i < mod; i++) {
        if ((key * i) % mod == 1)
            return i;
    }
    return -1;
}

string encrypt(string plaintext, int key) {
    string ciphertext = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            int p = ch - base;
            int c = (p * key) % 26;
            ciphertext += toupper(c + base);
        } else {
            ciphertext += toupper(ch);
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int key) {
    string plaintext = "";
    int inverseKey = modInverse(key, 26);
    if (inverseKey == -1) {
        cout << "Error: Key has no modular inverse under modulo 26." << endl;
        return "";
    }
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            int c = ch - base;
            int p = (c * inverseKey) % 26;
            if (p < 0) p += 26;
            plaintext += toupper(p + base);
        } else {
            plaintext += toupper(ch);
        }
    }
    return plaintext;
}

int main() {
    string plaintext;
    int key;
    cout << "Enter plaintext:"<<endl;
    cin >> plaintext;
    cout << "Enter key:"<<endl;
    cin >> key;
    string ciphertext = encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;
    return 0;
}