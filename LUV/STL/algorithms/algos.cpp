/* In algos like sort, lower_bound, min_element, etc we give the starting and ending location where we 
    want to find. The last location is exclusive so we give vector.end()(one more than the last location)*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    int min = *min_element(v.begin(),v.end()); // returns iterator and pointer in case of arrays
    cout << min << endl;
    int max = *max_element(v.begin(),v.end());
    cout << max << endl;

    int sum = accumulate(v.begin(),v.end(),0);  // Third parameter- initial value of sum
    cout << sum << endl;

    int cnt = count(v.begin(),v.end(),2);
    cout << cnt << endl;

    vector<int> ::iterator index = find(v.begin(),v.end(),9);  // iterator or pointer
    if(index != v.end()){
        cout << index-v.begin() << endl;
    }
    else
        cout << "Not found" << endl;

    reverse(v.begin(), v.end()); // same vector is reversed
    for(auto &val:v){
        cout << val << " ";
    }
    cout << endl;

    string s = "My String";
    reverse(s.begin()+3,s.end());
    cout << s << endl;

}