#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string removeSpaces(string str) {
    string result = "";
    for (char c : str) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

string encrypt(string message, vector<int> key) {
    string ciphertext = "";
    int key_size = key.size();
    message = removeSpaces(message);
    while (message.length() % key_size != 0) {
        message += 'z';
    }
    for (int i = 0; i < message.length(); i += key_size) {
        string block = message.substr(i, key_size);
        string permuted_block = block;
        for (int j = 0; j < key_size; ++j) {
            permuted_block[j] = block[key[j] - 1];
        }
        for (char &c : permuted_block) {
            c = toupper(c);
        }
        ciphertext += permuted_block;
    }
    return ciphertext;
}

string decrypt(string ciphertext, vector<int> key) {
    string message = "";
    int key_size = key.size();
    for (int i = 0; i < ciphertext.length(); i += key_size) {
        string block = ciphertext.substr(i, key_size);
        string permuted_block = block;
        for (int j = 0; j < key_size; ++j) {
            permuted_block[key[j] - 1] = block[j];
        }
        for (char &c : permuted_block) {
            c = toupper(c);
        }
        message += permuted_block;
    }
    return message;
}

int main() {
    int n;
    string message;
    vector<int> key;
    cout << "Enter the number of elements in the key: ";
    cin >> n;
    cout << "Enter the key elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        key.push_back(element); 
    }
    cin.ignore();
    cout << "Enter the message: ";
    getline(cin, message);
    string ciphertext = encrypt(message, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decrypted_message = decrypt(ciphertext, key);
    cout << "Decrypted message: " << decrypted_message << endl;
    return 0;
}