/*
lower_bound- returns the address of specified element if found else returns the next element
upper_bound- retunrs the address next element even if element is present
(for last element returns next address)

Array must be in sorted order- gives O(logN) else O(N)
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    // ********** FOR VECTORS
    /*vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    for(int i=0;i<n;++i){
        cout << a[i] << " ";
    }
    cout << endl;

    auto it = lower_bound(a.begin(), a.end(), 5);
    if(it == (a.end())){
        cout << "not found";
    }
    else
        cout << (*it) << endl;
    */

    //********** FOR SET
    set<int> s;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        s.insert(x);
    }
    auto it = lower_bound(s.begin(),s.end(),5);   // For map and sets Gives O(n)

    auto it1 = s.lower_bound(5);  // For set and maps gives O(logN) - in case of maps searches for keys
    cout << (*it) << endl;

}
