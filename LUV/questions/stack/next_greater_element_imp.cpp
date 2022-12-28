/*
Next Greater Element- the first element that is greater than the current element to its right
arr - 4 5 2 25 7 8

NGE array - 5 25 25 -1 8 -1   (for 4 NGE is 5, for 5 NGE is 25 and so on)
*/

// Push indexes instead of values in stack, better handling
#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &v){
    vector<int> nge(v.size());
    stack<int> st;
    for(int i=0;i<v.size();++i){
        while(!st.empty() && v[i] > v[st.top()]){
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
        
    while(!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }

    return nge;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    vector<int> nge = NGE(v);
    for(int i=0;i<n;++i){
        cout << v[i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;++i){
        cout << (nge[i] == -1?-1:v[nge[i]]) << " ";
    }
    cout << endl;   
}
