// Find the minimum element in unsorted sublist and place it at the end of sorted sublist
// (at the end of sorted sublist because we have already placed the mini. element at its right position)

#include<bits/stdc++.h>
using namespace std;

void selection(int arr[], int n){
    for(int i=0;i < n;++i){
        int minInd = i;
        for(int j=i+1;j<n;++j){
            if(arr[j] < arr[minInd])
                minInd = j;
        }
        swap(arr[i],arr[minInd]);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;++i) 
        cin >> arr[i];
    
    selection(arr,n);
    for(int i=0;i<n;++i) 
        cout << arr[i] << " ";
}