#include <bits/stdc++.h>
using namespace std;

string xorBinary(const string& a, const string& b) {
    if (a.length() != b.length()) {
        throw invalid_argument("Input strings must be of the same length.");
    }
    string result;
    result.reserve(a.length());
    for (size_t i = 0; i < a.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string mod2Div(const string& dividend, const string& divisor) {
    if (dividend.length() < divisor.length()) {
        throw invalid_argument("Dividend must be longer than or equal to divisor.");
    }
    if (divisor.empty()) {
        throw invalid_argument("Divisor cannot be empty.");
    }
    string tmp = dividend;
    size_t n = dividend.length();
    size_t divisorLen = divisor.length();
    for (size_t i = 0; i <= n - divisorLen; i++) {
        if (tmp[i] == '1') {
            for (size_t j = 0; j < divisorLen; j++) {
                tmp[i + j] = tmp[i + j] == divisor[j] ? '0' : '1';
            }
        }
    }
    return tmp.substr(tmp.length() - divisorLen + 1);
}

string encodeData(const string& data, const string& divisor) {
    string appendedData = data + string(divisor.length() - 1, '0');
    string remainder = mod2Div(appendedData, divisor);
    return data + remainder;
}

bool receiveData(const string& encodedData, const string& divisor) {
    string remainder = mod2Div(encodedData, divisor);
    cout << "Receiver remainder: " << remainder << endl;
    return remainder.find('1') == string::npos;
}

bool isValidBinary(const string& str) {
    return str.find_first_not_of("01") == string::npos;
}

int main() {
    string data;
    cout << "Data: ";
    cin >> data;
    string divisor;
    cout << "Divisor: ";
    cin >> divisor;

    cout << "\nSender side:" << endl;
    string encodedData = encodeData(data, divisor);
    string remainder = encodedData.substr(data.length());
    cout << "Dataword (n+k): " << data << string(divisor.length() - 1, '0') << endl;
    cout << "Encoded data: " << encodedData << endl;
    cout << "Remainder: " << remainder << endl;

    cout << "\nReceiver side:" << endl;
    cout << "Received Dataword (n+k): " << encodedData << endl;
    bool isValid = receiveData(encodedData, divisor);
    cout << (isValid ? "Approved" : "Discarded") << endl;

    return 0;
}