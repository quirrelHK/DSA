#include<bits/stdc++.h>
using namespace std;

void find_dup(int *arr, int size, int key){
    int *l = lower_bound(arr, arr + size,key);
    int *u = upper_bound(arr, arr+size,key);

    if(*l == size){
        cout << "Not";
    }
    else
        cout << key << " " << u - l;
}

int main(){
    int arr[] = {4,7,8,2,3,8,3,10,0,-7,11,69};

    int size = sizeof(arr)/sizeof(int);
    sort(arr, arr + size);     
    find_dup(arr,size,100);
}