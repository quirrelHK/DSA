#include<bits/stdc++.h>
using namespace std;
const int m = 1e7;    // golbal arrays can have size of order 10^7
int b[m];
int main(){
    int n = 1e5;   // locally the size of array is of order 10^5(stack memory is used). Greater than 10^5; segmentation fault (stack overflow)
    int a[n];
    // int b[m];
    b[m-1] = 5;
    a[n-1] = 4;
    cout << a[n-1] << endl;
    cout << b[m-1] << endl;
}