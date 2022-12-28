#include<bits/stdc++.h>
using namespace std;

int partition(int *,int ,int);
void quick(int *arr,int f, int r){
    int q;
    if(f < r){
        q = partition(arr,f,r);

        quick(arr,f,q-1);
        quick(arr,q+1,r);
    }
}

int partition(int *arr, int f, int r){
    int temp;
    int i = f - 1;
    for(int j = f; j < r; ++j){
        if(arr[j] <= arr[r]){
            temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
          
        }
    }

    temp = arr[++i];
    arr[i] = arr[r];
    arr[r] = temp;

    return i;
}

int main(){
    int arr[] = {4,7,8,2,3,8,3,10,0,-7,11,69};
    int size = sizeof(arr)/sizeof(int);
     
    quick(arr,0,size - 1);

    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
}