#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10; i>=0;--i){
        cout << ((num >>  i) & 1);
    }
    cout << endl;
}
int main(){
    // 1. Odd Even Check (last bit of odd number is SET)

    for(int i=0;i<=8;++i){
        printBinary(i);

        if(i&1){ // Anding of num with 1 (faster than modulo)
            cout << "Odd\n";
        }
        else{
            cout << "Even\n";
        }
    }


}