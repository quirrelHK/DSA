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
   int jump = sqrt(n), start = 0;
   int end = jump;
   while(key >= a[end] && end < n){
       start = end;
       end += jump;
       if(end > n - 1){
           end = n;
       }
   }

   for(int i = start; i < end; ++i){
        if(a[i] == key){
        found[cases][0] = 1;
        found[cases][1] = i + 1;
        return;
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