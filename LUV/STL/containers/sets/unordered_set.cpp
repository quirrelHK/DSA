/*
Same differences as maps and unordered_maps

cannot use complex data structures like vecotrs for keys in unordered_set
*/
#include<bits/stdc++.h>
using namespace std;

void printSet(unordered_set<string> &s){
    for(auto &value: s){
        cout << value << " ";
    }
    cout << endl;
}


int main(){
    unordered_set<string> s;
   
    s.insert("zfds");
    s.insert("ghj");
    s.insert("abc");
    // To access a element use find() - returns iterator
    auto it = s.find("abc"); //O(logN)
    if(it != s.end()){
        cout << (*it) << endl;
    }

    printSet(s);

    s.erase(it); // can take either element or iterator
    printSet(s);
}