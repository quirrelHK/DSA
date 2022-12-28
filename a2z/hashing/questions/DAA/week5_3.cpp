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

void find_common(int *arr_1, int *arr_2, int size_1, int size_2){

    int i = 0,j=0;
    while(i < size_1 && j < size_2){
        if(arr_1[i] == arr_2[j]){
            cout << arr_1[i] << " ";
            ++i;++j;
        }
        else if (arr_1[i] < arr_2[j]){
            ++i;
        }
        else
        ++j;
    }
    cout << '\n';
}

int main(){

    int cases,size_1,size_2;
    cin >> cases;
    for(int i = 0; i < cases; ++i){
        cin >> size_1;
        int *arr_1 = new int[size_1];
        input(arr_1, size_1);
        cin >> size_2;
        int *arr_2 = new int[size_2];
        input(arr_2,size_2);
        sort(arr_1, arr_1 + size_1);
        sort(arr_2, arr_2 + size_2);
        find_common(arr_1,arr_2,size_1,size_2);
        delete(arr_1);
        delete(arr_2);
    }
    return 0;
}
