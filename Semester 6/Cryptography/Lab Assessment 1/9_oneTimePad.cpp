#include<iostream>
#include<string>
using namespace std;

int main(){
    string plaintext, key, ciphertext;
    cout<<"Enter the plaintext: ";
    cin>>plaintext;
    cout<<"Enter the key: ";
    cin>>key;
    int n = plaintext.size();
    ciphertext = "";
    for(int i=0;i<n;i++){
        char t = (((plaintext[i]-'a')+(key[i]-'a'))%26)+'a';
        ciphertext += t;
    }
    cout<<"Ciphertext: "<<ciphertext<<endl;
}
