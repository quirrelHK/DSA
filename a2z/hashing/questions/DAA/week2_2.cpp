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


void find_sequence(int *a, int n, int cases, int sequence[][3]){
    for(int k = 2; k < n; ++k){
        for(int j = 1; j < k; ++j){
            for(int i = 0; i < k -1; ++i){
                if(a[i] + a[j] == a[k]){
                    sequence[cases][0] = i;
                    sequence[cases][1] = j;    
                    sequence[cases][2] = k;
                    return;    
                }
            }
        }
    }
    sequence[cases][0] = -1;
    return;
}

int main(){
    int size,cases;
    
    cin >> cases;
    int sequence[cases][3];

    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];

        input(arr,size);
        find_sequence(arr,size,i,sequence);
        delete(arr);
    }

    for(int i = 0; i < cases; ++i){
        if(sequence[i][0] == -1){
            cout << "Sequence not found." << endl;
        }
        else
            cout << sequence[i][0] << "," << sequence[i][1] << "," << sequence[i][2] << endl;
    }
    return 0;
}