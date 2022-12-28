#include<bits/stdc++.h>
using namespace std;

void reverseArr(int *arr,int f, int r){
    int temp;
    if(f<=r){
    temp = arr[f];
    arr[f]=arr[r];
    arr[r]=temp;
    reverseArr(arr,f+1,r-1);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;++i) cin >> arr[i];
    reverseArr(arr,0,n-1);

    for(int i=0;i<n;++i) cout << arr[i] << " ";
}