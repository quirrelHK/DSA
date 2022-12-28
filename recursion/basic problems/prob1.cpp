// Print name 5 times
#include<iostream>
using namespace std;

void fun(int i,int n){
    if(i >n)
        return;
    cout << "Name" << endl;;

    fun(i+1,n);
}

int main(){
    int n;
    cin >> n;
    fun(1,n);
}