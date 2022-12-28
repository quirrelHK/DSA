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

void selection_sort(int *a, int n, int values[2]){
    int compare = 0, swap = 0;
    int min;
    for(int i = 0; i < n - 1; ++i){
        min = i;
        for(int j = i + 1; j < n; ++j){
            ++compare;
            if(a[j] < a[min]){
                
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        ++swap;
    }
    
    values[0] = compare;
    values[1] = swap;
}
int main(){
    int size,cases;
    cin >> cases;
    int values[2];

    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];

        input(arr,size);
        selection_sort(arr,size,values);
        for(int i = 0; i < size; ++i){
            cout << arr[i] << " ";
        }
        cout << endl << "Comparisons = " << values[0] << endl << "Swaps = " << values[1] << endl;
        

        delete(arr);
    }
    
   
    return 0;
}