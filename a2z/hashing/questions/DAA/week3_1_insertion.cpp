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

void insertion_sort(int *a, int n, int values[2]){
    int key,i;
    int compare = 0,shift = 0;
    for(int j = 1; j < n; ++j){
        key = a[j];
        i = j - 1;
        
        while(i >= 0 && a[i] > key){
            compare += 1;
            a[i+1] = a[i];
            --i;
            shift += 1;
        }
        a[i + 1] = key;
        shift += 1;
    }
    values[0] = compare;
    values[1] = shift;
}
int main(){
    int size,cases;
    cin >> cases;
    int values[2];

    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];

        input(arr,size);
        insertion_sort(arr,size,values);
        for(int i = 0; i < size; ++i){
            cout << arr[i] << " ";
        }
        cout << endl << "Comparisons = " << values[0] << endl << "Shifts = " << values[1] << endl;
        

        delete(arr);
    }
    
   
    return 0;
}