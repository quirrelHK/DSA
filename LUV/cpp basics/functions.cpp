#include<bits/stdc++.h>
using namespace std;

void increment(int &n, int n1){  // Pass by reference and pass by value
    n++;
    n1++;
}

void func(string s){   // without & datatypes are always passed by value expect arrays
    s="";
}

void myfunc(int a[]){   // arrays are always passed by reference
    a[0] = 5;
}

/* while passing */
int main(){

    // int a = 4,b=4;
    // cout << a << " " << b << endl;
    // increment(a,b);
    // cout << a << " " << b << endl;

    // string strs = "my string";
    // func(strs);
    // cout << strs << endl;

    int a[10];
    a[0] = 7;
    myfunc(a);
    cout << a[0] << endl;

    // return statments defines the termination of a function
}