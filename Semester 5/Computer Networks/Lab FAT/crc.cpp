#include <bits/stdc++.h>
using namespace std;

string xorBinary(const string& a, const string& b) {
    string result;
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string mod2Div(string dividend, string& divisor) {
    int n = dividend.size(), divisorLen = divisor.size();
    for (int i = 0; i <= n - divisorLen; i++) {
        if (dividend[i] == '1') {
            string remainder = xorBinary(dividend.substr(i, divisorLen), divisor);
            for (int j = 0; j < divisorLen; j++) {
                dividend[i + j] = remainder[j];
            }
        }
    }
    return dividend.substr(n - divisorLen + 1);
}


string encodeData(const string& data, string& divisor) {
    string appendedData = data + string(divisor.size() - 1, '0');
    string remainder = mod2Div(appendedData, divisor);
    return data + remainder;
}

bool receiveData(const string& encodedData, string& divisor) {
    string remainder = mod2Div(encodedData, divisor);
    cout << "Receiver remainder: " << remainder << endl;
    return remainder.find('1') == string::npos;
}

int main() {
    string data, divisor;
    cout << "Data: ";
    cin >> data;
    cout << "Divisor: ";
    cin >> divisor;
    cout << "\nSender side:" << endl;
    string encodedData = encodeData(data, divisor);
    cout << "Encoded data: " << encodedData << endl;
    cout << "\nReceiver side:" << endl;
    bool isValid = receiveData(encodedData, divisor);
    cout << (isValid ? "Approved" : "Discarded") << endl;
    return 0;
}