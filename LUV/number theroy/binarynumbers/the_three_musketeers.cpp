
/*
using inclusion-exclusion principle for each subset of vowels(then size >= 3); if subset.size is even then we subtract else we add
store the count subset of volwes for each string, then we simply take the union of subsets but we also have to remove the intersection part

*/
#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
    if(ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u') return true;

    return false;
}

vector<string> subsets(string str){
    int sz = (1<<str.size());
    vector<string> ans;
    for(int mask=0;mask<sz;++mask){
        string subset;
        for(int bit=0;bit<str.size();++bit){
            if(mask & (1<<bit)) subset.push_back(str[bit]);
        }
        if(subset.size()) ans.push_back(subset);
    }
    return ans;
}

int main(){
    /*
      hsh: store of count of each subset of vowels string(aeiou) for every string    
      distinct_vw: store the string of vowels of each string
      Ex: 1. e->helen, irena-> iea, arthos->ao

    */
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> str(n);
        for(int i=0;i<n;++i){
            cin >> str[i];
        }

        unordered_map<string, int> hsh;
        for(int i=0;i<n;++i){
            set<char> distinct_vw;
            for(char &ch:str[i]){
                if(isVowel(ch)){
                    distinct_vw.insert(ch);
                }
            }
            string vowel_str;
            for(char ch:distinct_vw){
                vowel_str += ch;
            }
            vector<string> all_subsets = subsets(vowel_str);  // Here we make the subset of vowel for that particular string
            for(string &subset: all_subsets){
                hsh[subset]++;
            }
        }

        long long ans = 0;
        for(auto &pr:hsh){
            if(pr.second < 3) continue;    // If count of a subset < 3 then we cannot choose it
            long long cnt = pr.second;
            long long ways = (cnt * (cnt-1)*(cnt-2)/6);    // ways of choosing name of there are cnt number of names to choose from; 
                                                          // i.e. choosing 3 names from n names;nc3 = (n*(n-1)*(n-2))/6
            if(pr.first.size()%2==0) ans -= ways;     

            else ans += ways;
        }

        cout << ans << endl;

    }
}

