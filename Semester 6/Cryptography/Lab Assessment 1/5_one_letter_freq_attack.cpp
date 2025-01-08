#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const string ENGLISH_FREQ = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

unordered_map<char, int> calculateFrequencies(const string &ciphertext) {
    unordered_map<char, int> frequencies;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            frequencies[toupper(c)]++;
        }
    }
    return frequencies;
}

unordered_map<char, char> createMapping(unordered_map<char, int> &freqs) {
    vector<pair<char, int>> freqVec(freqs.begin(), freqs.end());
    sort(freqVec.begin(), freqVec.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second;
    });
    unordered_map<char, char> mapping;
    for (size_t i = 0; i < freqVec.size() && i < ENGLISH_FREQ.size(); ++i) {
        mapping[freqVec[i].first] = ENGLISH_FREQ[i];
    }
    return mapping;
}

string decrypt(const string &ciphertext, const unordered_map<char, char> &mapping) {
    string plaintext;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char upperC = toupper(c);
            char plainChar = mapping.count(upperC) ? mapping.at(upperC) : upperC;
            plaintext += islower(c) ? tolower(plainChar) : plainChar;
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    string ciphertext;
    cout << "Enter the ciphertext: " << endl;
    getline(cin, ciphertext);
    auto frequencies = calculateFrequencies(ciphertext);
    auto mapping = createMapping(frequencies);
    string plaintext = decrypt(ciphertext, mapping);
    cout << "Decrypted plaintext: " << plaintext << endl;
    return 0;
}