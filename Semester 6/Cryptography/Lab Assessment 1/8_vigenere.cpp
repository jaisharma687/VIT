#include <iostream>
#include <string>
using namespace std;

string vigenereEncrypt(string plaintext, string key) {
    string result = "";
    int keyIndex = 0;
    for (char &p : plaintext) {
        if (isalpha(p)) {
            p = toupper(p);
            int P = p - 'A';
            int K = toupper(key[keyIndex % key.length()]) - 'A';
            result += (P + K) % 26 + 'A';
            keyIndex++;
        } else {
            result += p;
        }
    }
    return result;
}

string vigenereDecrypt(string ciphertext, string key) {
    string result = "";
    int keyIndex = 0;
    for (char &c : ciphertext) {
        if (isalpha(c)) {
            c = toupper(c);
            int C = c - 'A';
            int K = toupper(key[keyIndex % key.length()]) - 'A';
            result += (C - K + 26) % 26 + 'A';
            keyIndex++;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string key;
    string message;
    cout << "Enter the key: " << endl;
    cin >> key;
    cin.ignore();
    cout << "Enter the message: " << endl;
    getline(cin, message);
    cout<< "Message: " << message << endl;
    string encrypted = vigenereEncrypt(message, key);
    cout << "Encrypted: " << encrypted << endl;
    string decrypted = vigenereDecrypt(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}
