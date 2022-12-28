/*
Red black tree is used
Inserting and accessing/finding time is O(logN)

Allows duplicate values

- multisets are used for implementing priority queue

*/
#include<bits/stdc++.h>
using namespace std;

void printSet(multiset<string> &s){
    for(auto &value: s){
        cout << value << " ";
    }
    cout << endl;
}


int main(){
    multiset<string> s;
   
    s.insert("zfds");  // O(logN)
    s.insert("ghj");
    s.insert("abc");
    s.insert("abc");
    s.insert("ghj");


    // To access a element use find() - returns iterator
    auto it = s.find("abc"); //O(logN)  - if duplicates are present then returns the iterator of first element
    if(it != s.end()){
        cout << (*it) << endl;
    }

    printSet(s);

    s.erase(it); // deletes only the value present at iterator
    printSet(s);

    s.erase("ghj"); // if we pass the element itself then deletes all duplicates
}

