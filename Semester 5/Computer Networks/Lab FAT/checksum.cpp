#include<bits/stdc++.h>
using namespace std;

string onesComplement(string s){
    string ans = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            ans += '1';
        }
        else{
            ans += '0';
        }
    }
    return ans;
}

string calculateChecksum(string originalData, int framesize){
    string checksum = "";
    int totallen = originalData.size();
    string totalsum = originalData.substr(0,framesize);
    for(int i = framesize; i < totallen; i += framesize){
        string currentFrame = originalData.substr(i,framesize);
        string additionResult = "";
        int sum = 0;
        int carry = 0;
        for(int k=framesize-1;k>=0;k--){
            sum += (currentFrame[k]-'0') + (totalsum[k]-'0');
            carry = sum / 2;
            additionResult = char((sum%2)+'0') + additionResult;
            sum = carry;
        }
        if(carry == 1){
            string carryHandledResult = "";
            for(int i = additionResult.size() - 1;i>=0;i--){
                if(carry==0){
                    carryHandledResult = additionResult[i] + carryHandledResult;
                }
                else if(((additionResult[i]-'0')+carry) % 2 == 0){
                    carryHandledResult = "0" + carryHandledResult;
                    carry = 1;
                }
                else{
                    carryHandledResult = "1" + carryHandledResult;
                    carry = 0;
                }
            }
            totalsum = carryHandledResult;
        }
        else totalsum = additionResult;
    }
    return onesComplement(totalsum);
}

bool verifychecksum(string recievedData,int framesize){
    string checksum = calculateChecksum(recievedData,framesize);
    return count(checksum.begin(),checksum.end(),'0') == framesize;
}

int main(){
    int framesize;
    cout<<"Enter frame size"<<endl;
    cin>>framesize;
    string originalData;
    cout<<"Enter original data"<<endl;
    cin>>originalData;
    string recievedData;
    cout<<"Enter recieved data"<<endl;
    cin>>recievedData;

    string checksum = calculateChecksum(originalData,framesize);
    string dataToSend = originalData + checksum;

    cout << "Original Data: " << originalData << endl;
    cout << "Frame Size: " << framesize << " bits" << endl;
    cout << "Checksum: " << checksum << endl;
    cout << "Data to be Sent: " << dataToSend << endl;
    
    if (verifychecksum(recievedData, framesize)) {
        cout << "Approved" << endl;
    } else {
        cout << "Discarded" << endl;
    }

    return 0;
}