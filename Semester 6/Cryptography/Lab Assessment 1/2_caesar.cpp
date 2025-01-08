#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string caesarEncrypt(string s,int key){
    string res = "";
    for(int i=0;i<s.size();i++){
        int ascii = s[i]-'a';
        int newAscii = (ascii+key)%26;
        char newChar = newAscii+'A';
        res += newChar;
    }
    return res;
}

void caesarDecrypt(string s){
    for(int key=1;key<26;key++){
        string res = "";
        for(int i=0;i<s.size();i++){
            int ascii = s[i]-'A';
            int newAscii = (ascii+key)%26;
            char newChar = newAscii+'A';
            res += newChar;
        }
        cout<<"Key: "<<key<<" -> Decrypted Text: "<<res<<endl;
    }
}

int main(){
    string plainText;
    int key;
    cout<<"Enter the plain text: "<<endl;
    cin>>plainText;
    cout<<"Enter the key: "<<endl;
    cin>>key;
    string cipherText = caesarEncrypt(plainText,key);
    cout<<"Cipher Text: "<<cipherText<<endl;
    cout<<"Decrypted Text: "<<endl;
    caesarDecrypt(cipherText);
    return 0;
}