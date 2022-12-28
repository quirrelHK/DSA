#include<bits/stdc++.h>
using namespace std;

void merge(int *, int , int, int);
void merge_sort(int *arr, int f, int r){
    if(f < r){
        int mid = (f + r)/2;
        merge_sort(arr,f,mid);
        merge_sort(arr,mid + 1,r);

        merge(arr,f,r,mid);
    }
}

void merge(int *arr, int f, int r, int mid){
    int n1 = mid - f + 1;
    int n2 = r - mid;

    int lArray[n1];
    int rArray[n2];

    for(int i = 0; i < n1; ++i){
        lArray[i] = arr[f + i];
    }
    for(int i = 0; i < n2; ++i){
        rArray[i] = arr[mid + i +1];
    }

    int i = 0,j = 0, k = f;

    while(i < n1 && j < n2){
        if(lArray[i] < rArray[j]){
            arr[k++] = lArray[i++];
        }
        else if(rArray[j] < lArray[i]){
            arr[k++] = rArray[j++];
        }
        else{
            arr[k++] = lArray[i++];
            arr[k++] = rArray[j++];
        }
    }

    while(i < n1){
        arr[k++] = lArray[i++];
    }
    while(j < n2){
        arr[k++] = rArray[j++];
    }
}

int main(){
    int arr[] = {4,7,8,2,3,8,3,10,0,-7,11,69};
    int size = sizeof(arr)/sizeof(int);
     
    merge_sort(arr,0,size - 1);

    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
}