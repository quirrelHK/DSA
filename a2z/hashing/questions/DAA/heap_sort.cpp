
#include<bits/stdc++.h>
using namespace std;

void max_heapify(int *a, int n, int i){
    int l = i*2 + 1;
    int r = i*2 + 2;
    int largest = i;
    if (l < n && a[l] > a[largest]){
        largest = l;
    }

    if (r < n && a[r] > a[largest]){
        largest = r;
    }

    if (i != largest){
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        max_heapify(a,n,largest);
    }
}
void build_max_heap(int *a, int n){
    for(int i = n/2 - 1; i >= 0; --i){
        max_heapify(a,n,i);
    }
}


void heap_sort(int *a, int n){
    build_max_heap(a,n);

    for(int i = n - 1; i > 0; --i){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        max_heapify(a,i,0);
    }

}
 

int main(){
    int arr[] = {51,8,1,7,3,-5,0,7,-5,77};
    int size = sizeof(arr)/sizeof(int);

    heap_sort(arr,size);

    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}
