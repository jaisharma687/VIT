#include<bits/stdc++.h>
using namespace std;

const int K = 26;

int modInverse(int a, int m) {
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

vector<int> multiplyMatrix(const vector<vector<int>> &key, const vector<int> &text) {
    vector<int> result(3);
    for (int i = 0; i < 3; ++i) {
        result[i] = 0;
        for (int j = 0; j < 3; ++j) {
            result[i] += key[i][j] * text[j];
        }
        result[i] %= K;
    }
    return result;
}

string prepareText(const string &text) {
    string prepared;
    for (char c : text) {
        if (isalpha(c)) {
            prepared += toupper(c);
        }
    }
    while (prepared.size() % 3 != 0) {
        prepared += 'X';
    }
    return prepared;
}

string encrypt(const string &text, const vector<vector<int>> &key) {
    string ciphertext;
    for (size_t i = 0; i < text.size(); i += 3) {
        vector<int> plainVec = {text[i] - 'A', text[i + 1] - 'A', text[i + 2] - 'A'};
        vector<int> cipherVec = multiplyMatrix(key, plainVec);
        for (int val : cipherVec) {
            ciphertext += (val + 'A');
        }
    }
    return ciphertext;
}

string decrypt(const string &text, const vector<vector<int>> &key) {
    int det = key[0][0] * (key[1][1] * key[2][2] - key[1][2] * key[2][1]) -
              key[0][1] * (key[1][0] * key[2][2] - key[1][2] * key[2][0]) +
              key[0][2] * (key[1][0] * key[2][1] - key[1][1] * key[2][0]);
    det = (det % K + K) % K;
    int detInverse = modInverse(det, K);
    if (detInverse == -1) {
        cerr << "Key matrix is not invertible. Decryption not possible." << endl;
        return "";
    }
    vector<vector<int>> adj(3, vector<int>(3));
    adj[0][0] = (key[1][1] * key[2][2] - key[1][2] * key[2][1]) % K;
    adj[0][1] = (key[0][2] * key[2][1] - key[0][1] * key[2][2]) % K;
    adj[0][2] = (key[0][1] * key[1][2] - key[0][2] * key[1][1]) % K;
    adj[1][0] = (key[1][2] * key[2][0] - key[1][0] * key[2][2]) % K;
    adj[1][1] = (key[0][0] * key[2][2] - key[0][2] * key[2][0]) % K;
    adj[1][2] = (key[0][2] * key[1][0] - key[0][0] * key[1][2]) % K;
    adj[2][0] = (key[1][0] * key[2][1] - key[1][1] * key[2][0]) % K;
    adj[2][1] = (key[0][1] * key[2][0] - key[0][0] * key[2][1]) % K;
    adj[2][2] = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % K;
    for (auto &row : adj) {
        for (int &val : row) {
            val = (val * detInverse % K + K) % K;
        }
    }
    string plaintext;
    for (size_t i = 0; i < text.size(); i += 3) {
        vector<int> cipherVec = {text[i] - 'A', text[i + 1] - 'A', text[i + 2] - 'A'};
        vector<int> plainVec = multiplyMatrix(adj, cipherVec);
        for (int val : plainVec) {
            plaintext += (val + 'A');
        }
    }
    return plaintext;
}

int main() {
    string text;
    cout << "Enter the Plain text for Encryption: ";
    getline(cin, text);
    text = prepareText(text);
    cout << "Padded Text: " << text << endl;
    vector<vector<int>> key = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    cout << "Key Matrix: " << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << key[i][j] << " ";
        }
        cout << endl;
    }
    string encrypted = encrypt(text, key);
    cout << "Encrypted Message: " << encrypted << endl;
    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted Message: " << decrypted << endl;
    return 0;
}