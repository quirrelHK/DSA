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

int partition(int *,int,int,int &,int &);
void quick_sort(int *a, int p, int r, int &compare, int &swaps){
    int q;
    if (p < r){
        q = partition(a,p,r,compare,swaps);

        quick_sort(a,p,q-1,compare,swaps);
        quick_sort(a,q+1,r,compare,swaps);
    }
}

int partition(int *a, int p, int r,int &compare, int &swaps){
    int temp;
    int i = p - 1;
    for(int j = p; j < r; ++j){
        ++compare;
        if(a[j] <= a[r]){
            ++swaps;
            ++i;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;

        }
    }
    ++swaps;
    temp = a[++i];
    a[i] = a[r];
    a[r]= temp;
    return i;
}

int main(){
    int size,cases;
    int compare = 0, swaps = 0;
    
    cin >> cases;
    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];

        input(arr,size);
        quick_sort(arr,0,size - 1,compare,swaps);
        for(int i = 0; i < size; ++i){
            cout << arr[i] << " ";
        }
        cout << endl << "Comparisons = " << compare << endl << "Swaps = " << swaps << endl;
        

        delete(arr);
    }
    
   
    return 0;
}