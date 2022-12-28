// class that stroes two values

#include<bits/stdc++.h>
using namespace std;


int main(){
    pair<int, string> p1,p2;

    // Enter values
    p1 = make_pair(2,"abc");
    p2 = {3,"acca"};
    cout << p1.first << " " << p1.second << endl;

    // pair<int,string> p3 = p1;  // copy of p is passed not reference
    pair<int, string> &p3 = p1; // reference
    p3.first = 4;
    cout << p1.first << " " << p1.second << endl;

    // Pairs are used to maintain relation between values
    pair<int,int> p_arr[3];
    p_arr[0] = {1,2};
    p_arr[1] = {2,3};
    p_arr[2] = {3,4};

    swap(p_arr[0],p_arr[2]);  // while swapping the relationship is maintained
    for(int i=0;i <3;++i){
        cout << p_arr[i].first << " " << p_arr[i].second <<  endl;
    }

    // Taking input
    pair<int,int> p;
    cin >> p.first;
    cout << p.first;


}