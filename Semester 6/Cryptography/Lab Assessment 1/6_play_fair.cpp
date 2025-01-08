#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<char>> generateKeyMatrix(const string &key) {
    unordered_set<char> used;
    vector<vector<char>> keyMatrix(5, vector<char>(5));
    string processedKey;
    for (char c : key) {
        c = toupper(c);
        if (c == 'J') c = 'I';
        if (used.find(c) == used.end() && isalpha(c)) {
            processedKey += c;
            used.insert(c);
        }
    }
    int idx = 0;
    for (char c : processedKey) {
        keyMatrix[idx / 5][idx % 5] = c;
        idx++;
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c == 'J') continue;
        if (used.find(c) == used.end()) {
            keyMatrix[idx / 5][idx % 5] = c;
            idx++;
        }
    }
    return keyMatrix;
}

pair<int, int> findPosition(const vector<vector<char>> &keyMatrix, char c) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (keyMatrix[i][j] == c) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

string prepareText(const string &text) {
    string prepared;
    for (char c : text) {
        if (isalpha(c)) {
            prepared += toupper(c == 'J' ? 'I' : c);
        }
    }
    for (size_t i = 0; i < prepared.length(); i += 2) {
        if (i + 1 == prepared.length() || prepared[i] == prepared[i + 1]) {
            prepared.insert(i + 1, 1, 'Z');
        }
    }
    return prepared;
}

string processText(const string &text, const vector<vector<char>> &keyMatrix, bool encrypt) {
    string result;
    for (size_t i = 0; i < text.length(); i += 2) {
        auto pos1 = findPosition(keyMatrix, text[i]);
        auto pos2 = findPosition(keyMatrix, text[i + 1]);
        if (pos1.first == pos2.first) {
            result += keyMatrix[pos1.first][(pos1.second + (encrypt ? 1 : 4)) % 5];
            result += keyMatrix[pos2.first][(pos2.second + (encrypt ? 1 : 4)) % 5];
        } else if (pos1.second == pos2.second) {
            result += keyMatrix[(pos1.first + (encrypt ? 1 : 4)) % 5][pos1.second];
            result += keyMatrix[(pos2.first + (encrypt ? 1 : 4)) % 5][pos2.second];
        } else {
            result += keyMatrix[pos1.first][pos2.second];
            result += keyMatrix[pos2.first][pos1.second];
        }
    }
    return result;
}

int main() {
    string key, plaintext;
    cout << "Enter keyword: "<<endl;
    cin >> key;
    vector<vector<char>> keyMatrix = generateKeyMatrix(key);
    cout << "Generated Key Matrix:\n";
    for (const auto &row : keyMatrix) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << '\n';
    }
    cout << "Enter message to encrypt: ";
    cin.ignore();
    getline(cin, plaintext);
    plaintext = prepareText(plaintext);
    string encryptedText = processText(plaintext, keyMatrix, true);
    cout << "\nEncrypting...\nThe encrypted text is: " << encryptedText << '\n';
    string decryptedText = processText(encryptedText, keyMatrix, false);
    cout << "\nDecrypting...\nThe decrypted text is: " << decryptedText << '\n';
    return 0;
}