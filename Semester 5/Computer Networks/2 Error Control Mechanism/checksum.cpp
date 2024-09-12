#include <bits/stdc++.h>
using namespace std;

string calculateOnesComplement(string binaryString) {
    for (int i = 0; i < binaryString.length(); i++) {
        binaryString[i] = (binaryString[i] == '0') ? '1' : '0';
    }
    return binaryString;
}

string computeChecksum(string originalData, int frameSize) {
    int originalDataLength = originalData.length();
    if (originalDataLength % frameSize != 0) {
        int paddingSize = frameSize - (originalDataLength % frameSize);
        originalData = string(paddingSize, '0') + originalData;
    }

    originalDataLength = originalData.length();

    string totalSum = originalData.substr(0, frameSize);
    for (int i = frameSize; i < originalDataLength; i += frameSize) {
        string currentFrame = originalData.substr(i, frameSize);
        string additionResult = "";
        int sum = 0, carry = 0;
        for (int k = frameSize - 1; k >= 0; k--) {
            sum += (currentFrame[k] - '0') + (totalSum[k] - '0');
            carry = sum / 2;
            additionResult = char((sum % 2) + '0') + additionResult;
            sum = carry;
        }
        if (carry == 1) {
            string carryHandledResult = "";
            for (int l = additionResult.length() - 1; l >= 0; l--) {
                if (carry == 0) {
                    carryHandledResult = additionResult[l] + carryHandledResult;
                } else if (((additionResult[l] - '0') + carry) % 2 == 0) {
                    carryHandledResult = "0" + carryHandledResult;
                    carry = 1;
                } else {
                    carryHandledResult = "1" + carryHandledResult;
                    carry = 0;
                }
            }
            totalSum = carryHandledResult;
        } else {
            totalSum = additionResult;
        }
    }
    return calculateOnesComplement(totalSum);
}

bool verifyChecksum(string receivedData, int frameSize) {
    string receiverChecksum = computeChecksum(receivedData, frameSize);
    return count(receiverChecksum.begin(), receiverChecksum.end(), '0') == frameSize;
}

int main() {
    string originalData, receivedData;
    int frameSize;
    cout << "Enter the original data (binary string): ";
    cin >> originalData;
    cout << "Enter the received data (binary string): ";
    cin >> receivedData;
    cout << "Enter the frame size (number of bits per frame): ";
    cin >> frameSize;
    
    // Compute checksum and data to be sent
    string checksum = computeChecksum(originalData, frameSize);
    string dataToSend = originalData + checksum;
    
    cout << "Original Data: " << originalData << endl;
    cout << "Frame Size: " << frameSize << " bits" << endl;
    cout << "Checksum: " << checksum << endl;
    cout << "Data to be Sent: " << dataToSend << endl;
    
    // Verify received data
    if (verifyChecksum(receivedData, frameSize)) {
        cout << "Approved" << endl;
    } else {
        cout << "Discarded" << endl;
    }
    
    return 0;
}
