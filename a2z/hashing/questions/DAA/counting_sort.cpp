#include<bits/stdc++.h>
using namespace std;

void counting_sort(int *a, int *b, int k,int n){
    int c[k+1];
    for(int i = 0; i < k; ++i){
        c[i] = 0;
    }
     for(int i = 0; i < n; ++i){
        c[a[i]]+= 1;
    }

    for(int i = 1; i < k; ++i){
        c[i] = c[i-1] + c[i];
    }

    for(int i = n; i >= 0; --i){
        b[ c[ a[i] ] ] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
}

int main(){
    int arr[] = {2,5,8,9,3,1,4,2,0,3,8,6,2,3,8,6,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int b[n];
    int k = 9;

    counting_sort(arr,b,k,n);

    for(int i = 0; i < n; ++i){
        cout << b[i] << " ";
    }
    return 0;
}