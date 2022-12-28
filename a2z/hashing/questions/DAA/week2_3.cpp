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

int find(int *a, int f, int r, int key){
    int front = f, rear = r, mid;
    while(front <= rear){

        mid = front + (rear - front)/2;

        if(key == a[mid]){
            return 1;
        }
        if(key > a[mid]){
            front = mid + 1;
        }
        else{
            rear = mid - 1;
        }
    }
    return 0;
}
int find_pairs(int *a, int n, int key){
    int temp, count = 0;
    for(int i = 0; i < n; ++i){
        temp = key + a[i];
        count += find(a,i+1,n,temp);
    }
    return count;
}

int main(){
    int size,key,cases;
    cin >> cases;
    int pairs[cases];
    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];
    
        input(arr,size);
        sort(arr, arr + size);
        cin >> key;
        pairs[i] = find_pairs(arr,size,key);
        delete(arr);
    }

    for(int i = 0; i < cases; ++i){
        cout << pairs[i] << endl;
    }
    return 0;
}