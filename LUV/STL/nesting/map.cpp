// We can do having nesting in normal maps, containers allow comparison like between pair,sets,etc. 
// And these values are inserted in sorted order based on this comparison

#include<bits/stdc++.h>
using namespace std;


int main(){

    map<pair<string, string>, vector<int>> m;   // First name, last name and marks
    // pair<int, int> p1,p2;
    // p1 = {2,2};
    // p2 = {2,3};
    // cout << (p1 < p2);  // Comparison in containers

    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        string fn,ln;
        int cnt;
        cin >> fn >> ln >> cnt;
        for(int j=0;j<cnt;++j){
            int x;
            cin >> x;
            m[{fn,ln}].push_back(x);  // m[{fn,ln}] -> will give a vector, and then you can append to that vector
        }
    }
    for(auto &pr:m){
        auto &full_name = pr.first;
        auto &list = pr.second;
        cout << full_name.first << " " << full_name.second << endl;
        cout << list.size() << endl;
        for(auto &marks: list){
            cout << marks << " " ;
        }
        cout << endl;
    }
}