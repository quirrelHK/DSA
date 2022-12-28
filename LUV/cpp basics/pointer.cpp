#include<bits/stdc++.h>
using namespace std;

void increment(int *x){
    (*x)++;
}

int main(){
    int a=4;
    cout << a << endl; 
    increment(&a);
    cout << a << endl;
}



// int main(){

//     int a[10];
//     a[0]=2;
//     a[1]=4;
//     cout << "a: " << a << endl;
//     cout << "&a[0]: " << &a[0] << endl;
//     cout << "*a: " << *a << endl;
//     cout << "a+1: " << a+1 << endl;
//     cout << "&a[1]: " << &a[1] << endl;
// }




// int main(){
//     int x = 4;
//     int *p_x = &x;

//     cout << "Add X: " << (int)&x << endl;
//     cout << "Val p_x: " << p_x << endl;
//     cout << "Val *p_x: " << *p_x << endl;

//     *p_x = 6;
//     cout << "X: " << x << endl;
//     cout << "p_x + 1: " << p_x  + 1 << endl;  // size of data type is added

//     int **pp_x = &p_x;
//     cout << "Add P_x: " << pp_x << endl;
//     cout << "Val pp_x: " << pp_x << endl;
//     cout << "Val *pp_x: " << **pp_x << endl;
//     cout << "Val **pp_x: " << **pp_x << endl;

//     **pp_x = 10;
//     cout << "X: " << x << endl;

// }