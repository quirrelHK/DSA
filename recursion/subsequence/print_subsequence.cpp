#include<bits/stdc++.h>
using namespace std;

void print_sub(int ind, vector<int> &sub, vector<int> arr, int n){
    if (ind >= n){
        if (sub.size() == 0){
            cout << "{}";
        }
        else if (sub.size()==5){
        for(auto it: sub){
            cout << it << " "; 
        }
        }
        cout << endl;
        return;
    }

    // For the particular we index or element we want to take
    sub.push_back(arr[ind]);
    print_sub(ind+1,sub,arr,n);

    // For the index we do not want to take
    sub.pop_back();
    print_sub(ind+1,sub,arr,n);

    // We can also change to the order of take and not take
}


int main(){

    vector<int> arr = {3,4,5,3,4,5};
    int n = arr.size();
    vector<int> sub;
    print_sub(0,sub,arr,n);
    return 0;
}