/*
Given a string S of lower case English alphabet of length N and two integers L and R he want to know whether
all the letters of the substring from index L to R(inclusive) can be rearranged to form a palindrome or not. 
He want to know this for Q values of L and R.
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;  // size of string and queries 
        string s;
        cin >> s;
        while(q--){
            int l,r;
            cin >> l >> r;
            int hash[26];
            for(int i=0;i<26;++i){
                hash[i]=0;
            }
            l--;r--;  // because array is 0-indexed here
            for(int i=l;i<=r;++i){
                hash[s[i]-'a']++;
            }
            int oddCnt=0;
            for(int i=0;i<26;++i){
                if(hash[i]%2 != 0)
                    oddCnt++;
            }
            if(oddCnt > 1) cout << "\nNo";
            else cout << "\nYes";
        }
    }
}