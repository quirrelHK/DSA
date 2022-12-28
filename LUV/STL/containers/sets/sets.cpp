/*
Insertion- O(logN)
Sets are stored in sorted order

red black trees
*/

#include<bits/stdc++.h>
using namespace std;

void printSet(set<string> &s){
    for(auto &value: s){
        cout << value << " ";
    }
    cout << endl;
}


int main(){
    set<string> s;
   
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