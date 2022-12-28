#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10; i>=0;--i){
        cout << ((num >>  i) & 1);
    }
    cout << endl;
}
int main(){
    int n=5;

    cout << (n>>1) << endl; // Divide by 2

    cout << (n<<1) << endl; // Multiply by 2


}