// print all subsequence/substrings

#include<bits/stdc++.h>
using namespace std;


int main(){
    string s = "abc";
    int n = s.length();

    for(int i = 0; i < pow(2,n); ++i){
        string sub = "";
        for (int j = 0; j < n; ++j){
            if(i & (1 << j)){
                sub += s[j];
            }
        }
        if (sub == "")
            cout << "{}" << " ";
        else
            cout << sub << " ";
    }
    return 0;
}