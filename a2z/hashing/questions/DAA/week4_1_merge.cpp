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

void merge(int *a, int f, int r, int mid, int &compare, int &swaps){
    int n1 = mid - f + 1;
    int n2 = r - mid;
     
    int LeftArray[n1];
    int RightArray[n2];
    for(int i = 0; i < n1; ++i){
        LeftArray[i] = a[f + i];
    }

    for(int i = 0; i < n2; ++i){
        RightArray[i] = a[mid + i + 1];
    }

    int i = 0, j = 0, k = f;

    while( i < n1 && j < n2){
        
        compare++;
        if(LeftArray[i] <= RightArray[j]){
            a[k++] = LeftArray[i++];
            // swaps++;
        }
        else{
            a[k++] = RightArray[j++];
            swaps++;
        }
    }

    while(i < n1){

        a[k++] = LeftArray[i++];
        // swaps++;
    }

    while(j < n2){
        a[k++] = RightArray[j++];
        // swaps++;
    }
}
void merge_sort(int *a, int f, int r, int &compare, int &swaps){
    if (f < r){
        int mid = (f+r)/2;
        merge_sort(a,f,mid,compare,swaps);
        merge_sort(a,mid+1,r,compare,swaps);

        merge(a,f,r,mid,compare,swaps);

    }

}
int main(){
    int size,cases;
    int compare = 0, swaps = 0;
    
    cin >> cases;
    for(int i = 0; i < cases; ++i){
        cin >> size;
        int *arr = new int[size];

        input(arr,size);
        merge_sort(arr,0,size - 1,compare,swaps);
        for(int i = 0; i < size; ++i){
            cout << arr[i] << " ";
        }
        cout << endl << "Comparisons = " << compare << endl << "Inversions = " << swaps << endl;
        

        delete(arr);
    }
    
   
    return 0;
}