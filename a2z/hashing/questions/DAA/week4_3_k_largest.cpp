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

int partition(int arr[], int p, int r);
 
int k_smallest(int arr[], int p, int r, int k)
{
   
    if (k > 0 && k <= r - p + 1) {
   
        int pos = partition(arr, p, r);

        if (pos - p == k - 1)
            return arr[pos];
        if (pos - p > k - 1) 
            return k_smallest(arr, p, pos - 1, k);
 

        return k_smallest(arr, pos + 1, r, k - pos + p - 1);
    }
 
    return -1;
}
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int partition(int arr[], int p, int r)
{
    int x = arr[r], i = p;
    for (int j = p; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 

int main(){
    int size,key,cases;
    cin >> cases;

    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];

        input(arr,size);
        cin >> key;
        int result = k_smallest(arr,0,size - 1,key);
        if(result == -1){
            cout << "Not Present" << '\n';
        }
        else
            cout << result << '\n';
        

        delete(arr);
    }
    
   
    return 0;
}