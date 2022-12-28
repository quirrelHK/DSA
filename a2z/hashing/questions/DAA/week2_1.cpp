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

int count_duplicate(int *a, int n, int key){

    int *low = lower_bound(a, a + n ,key);

    if(low == (a + n) || *low != key){
        return 0;
    }

    int *high = upper_bound(low, a + n, key);


    return high - low;
}



int main(){
    int cases;
    
    cin >> cases;
    int key_value[cases][2];

    for(int i = 0; i < cases; ++i){
        int size,key;
        cin >> size;
        int *arr = new int[size];
        input(arr,size);

        cin >> key;
        key_value[i][0] = key;
        key_value[i][1] = count_duplicate(arr,size,key);


        delete(arr);
    }
    cout << endl;
    for(int i = 0; i < cases; ++i){
        cout << key_value[i][0] << "-" << key_value[i][1] << endl;
    }
    return 0;
}