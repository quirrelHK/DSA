// key and value pairs

// insertions takes O(logN). But, if we have "string" type of keys because there is comparison between keys complexity increases - O(s.size()*logN) (s.size()-> size of string being inserted)
// Accessing i.e. simply (it->first) also take O(logN)
// find() -> O(logN)
// erase() -> O(logN)
#include<bits/stdc++.h>
using namespace std;

void printMap(map<int, string> &m){
    cout << m.size() << endl;
    for(auto it=m.begin();it!=m.end();++it){  // O(NlogN)
        cout << (it->first) << " " << (it->second) << endl; // printed in sorted order
    }
}

int main(){


    map<int, string> m;
    m[1] = "a";   // O(logN)
    m[5] = "bb";
    m[3] = "abc";
    m.insert({4,"adf"}); // O(logN)
    m[6];  // for - string: default value(empty string)  - int: default value(0)
    
    cout << "Find:\n";
   /* auto it = m.find(0);  // find returns iterator. If value is not found then return .end()
    if(it == m.end()){
        cout << "No value\n";
    }
    else{
        cout << (it->first) << " " << (it->second) << endl;
    }
    */

    cout << "Erase:\n";
    // erase takes either key or iterator input
    m.erase(3); // taking key
    printMap(m);
    auto it = m.find(5);
    cout << endl;
    m.erase(it);
    printMap(m);

    it = m.find(7); // m.end()
    // m.erase(it); // segmentation fault
    if(it != m.end())
        m.erase(it);

    cout << "Clear:\n";
    m.clear();
    printMap(m);
}