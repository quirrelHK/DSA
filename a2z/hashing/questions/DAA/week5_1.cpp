/*Name: Ritesh Singh
Sec: C
Roll No: 52
Student ID: 20011347*/

#include<bits/stdc++.h>
using namespace std;

void input(char *a, int n){
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void max_count(char *arr, int size){
    int count[256] = {0};

    for(int i = 0; i < size; ++i){
        count[arr[i]]++;
    }

    int largest = count[0], index = 0;
    for(int i = 1; i < 256; ++i){
        if (largest < count[i]){
            largest = count[i];
            index = i;
            }
    }

    if (largest == 1){
    cout << "No Duplicates.\n";
    }
    else{
        cout << (char)index << " - " << count[index] <<'\n';
    }

}

int main(){

    int cases,size;
    cin >> cases;
    for(int i = 0; i < cases; ++i){
        cin >> size;
        char *arr = new char[size];

        input(arr, size);
        
        max_count(arr,size);
        delete(arr);
    }
    return 0;
}

