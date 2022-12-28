/*Name: Ritesh Singh
Sec: C
Roll No: 52
Student ID: 20011347*/
#include<bits/stdc++.h>
using namespace std;

void input(int *a, int n){
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

int binary_search(int *a, int f,int size, int key){
    int r = size - 1;
    
    while(f <= r){
        int mid = f + (r - f)/2;

        if(a[mid] == key){
            return mid;
        } 

        else if (a[mid] < key){
            f = mid + 1;
        } 
        else    
            r = mid - 1;
    }

    return size;
}

void find_sum(int *a, int size, int total){
    int i, key_1,found;
    
    for(i = 0; i < size; ++i){
        key_1 = total - a[i];
        found = binary_search(a,i+1,size,key_1);
        if(found < size){
            cout << a[i] << " " << key_1 << '\n';
            return; 
        }
    }
    cout << "No Such key present.\n";
}


int main(){

    int cases,size,key;
    cin >> cases;
    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];
        
        input(arr, size);
        cin >> key;
        sort(arr, arr + size);
        find_sum(arr,size,key);
        
        delete(arr);
    }
    return 0;
}
