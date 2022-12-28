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

void find(int *a, int n, int key, int found[][2], int cases){
    int front = 0, rear = n - 1, mid;
    while(front <= rear){

        mid = front + (rear - front)/2;

        if(key == a[mid]){
            found[cases][0] = 1;
            found[cases][1] = mid + 1;
            return;
        }
        if(key > a[mid]){
            front = mid + 1;
        }
        else{
            rear = mid - 1;
        }
    }
    found[cases][0] = -1;
    found[cases][1] = n + 1;
    return;
}
int main(){
    int size,key,cases;
    
    cout << "Input:" << endl;
    cin >> cases;
    int found[cases][2];

    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];

        input(arr,size);

        sort(arr, arr + size);

        cin >> key;

        find(arr,size,key,found,i);

        

        delete(arr);
    }
    cout << "\nOutput:" << endl;
    for(int i = 0; i < cases; ++i){
        if(found[i][0] == 1){
            cout << "Present " << found[i][1] << endl;
        }
        else
            cout << "Not Present " << found[i][1] << endl;
    }
    return 0;
}