//1. Merge: if we have 2 sorted arrays, merge them (maintaining the sorted order) - O(n1+n2) == O(n)

/*2. Sorting: divide the unsorted array in equal halves until we get sorted subarray(we will do this until only 1 element remains i.e. sorted subarray) 
     once we get the sorted arrays we can go ahead with the step of merging - O(logN): because we are dividing by 2 until we can divide*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N];

void merge(int l, int r, int mid){
    int l_size = mid - l + 1;
    int r_size = r - mid;
    int L[l_size+1],R[r_size+1];

    for(int i=0;i<l_size;++i){
        L[i]=arr[i+l];
    }

    for(int i=0;i<r_size;++i){
        R[i]=arr[i+mid+1];
    }
    L[l_size] = R[r_size] = INT_MAX;

    int l_ind =0, r_ind = 0;
    for(int i=l;i<=r;++i){
        if(L[l_ind] <= R[r_ind]){
            arr[i]=L[l_ind];
            l_ind++;
        }
        else{
            arr[i]=R[r_ind];
            r_ind++;
        }
    }
}

void mergeSort(int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        merge(l,r,mid);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i) 
        cin >> arr[i];
    
    mergeSort(0,n-1);
    for(int i=0;i<n;++i) 
        cout << arr[i] << " ";
}