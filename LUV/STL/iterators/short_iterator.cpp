#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v = {2,3,4,5,7};

    // range based loops - works for all containers
   
    cout << "Range based loops\n";
   /* for(int value:v){  // this value is just a copy
        value++;
    }
    for(int value:v){
        cout << value << " ";
    }
    cout << endl;

    for(int &value:v){  // reference
        ++value;
    }
    for(int value:v){
        cout << value << " ";
    }
    cout<<endl;

    vector<pair<int,int>> v_p = {{1,2},{3,4},{5,6}};
    for(pair<int,int> &value:v_p){
        cout << value.first << " " << value.second << endl;
    }
    */

//    cout << "Auto keyword\n";
//    // auto keyword automatically determines the datatye of a variable

//    auto a = 1;
//    auto b = "mystring";
//    cout << a << " " << b << endl;

//    for(auto &value: v){
//     cout << value << " ";
//    }
//    cout << endl;
    int arr[] = {1,2,3,4};
    for(auto &val:arr){
        cout << val << endl;
    }
}