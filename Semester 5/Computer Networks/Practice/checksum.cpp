#include<bits/stdc++.h>
using namespace std;

string onesComplement(string s){
    string ans= "";
    for(int i=0;i<s.size();i++){
        if(s[i] == '0'){
            ans += '1';
        }
        else{
            ans += '0';
        }
    }
    return ans;
}

string checkSumCal(string data,int fs){
    string checkSum = "";
    int dataLen = data.size();
    string totalData = data.substr(0,fs);
    for(int i=fs;i<dataLen;i+=fs){
        string current = data.substr(i,fs);
        string additionResult = "";
        int sum=0;
        int carry=0;
        for(int k=fs-1;k>=0;k--){
            sum += (current[k]-'0') + (totalData[k]-'0');
            carry = sum/2;
            additionResult = char(sum%2 + '0') + additionResult;
            sum = carry;
        }
        if(carry==1){
            string carryResult = "";
            for(int j=additionResult.size()-1;j>=0;j--){
                if(carry == 0){
                    carryResult = additionResult[j] + carryResult;
                }
                else if(((additionResult[j]-'0')+carry)%2==0){
                    carryResult = "0" + carryResult;
                    carry = 1;
                }
                else{
                    carryResult = "1" + carryResult;
                    carry = 0;
                }
            }
            totalData = carryResult;
        }
        else{
            totalData = additionResult;
        }
    }
    return onesComplement(totalData);
}

bool verifyChecksum(string rData, int fs){
    string checkSum = checkSumCal(rData,fs);
    return count(checkSum.begin(),checkSum.end(),'0') == fs;
}

int main(){
    string data;
    string recievedData;
    int frameSize;
    cout<<"Enter the data to be sent: ";
    cin>>data;
    cout<<"Enter the data recieved: ";
    cin>>recievedData;
    cout<<"Enter the frame size: ";
    cin>>frameSize;

    string sentData = data + checkSumCal(data,frameSize);

    cout<<"Sent Data: "<<sentData<<endl;
    cout<<"Recieved Data: "<<recievedData<<endl;
    if(verifyChecksum(recievedData,frameSize)){
        cout<<"Checksum is valid"<<endl;
    }
    else{
        cout<<"Checksum is invalid"<<endl;
    }
    return 0;
}