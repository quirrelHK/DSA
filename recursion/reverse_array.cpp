#include<iostream>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void reverse(int *arr, int i, int n){
    if(i >= n/2) return;

    swap(arr[i],arr[n-i-1]);
    reverse(arr,i+1,n);
}

int main(){
    int arr[] = {1,5,6,8,9};
    int n = sizeof(arr)/sizeof(int);

    reverse(arr,0,n);

    for(int i = 0; i < n; ++i)
            cout << arr[i] << " ";
}