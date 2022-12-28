/* 
All the functions are same as normal maps the only difference is in:
1. inbuilt implementation - hashtales are used(for each key hash value is calculated)
2. time complexity
3. valid keys datatype - we cannot use containers(like vectors,pairs,etc) for keys in these maps because hash functions are not defined for those
 */

/*
Time complexity of insertion and accessing/finding is theta(1)
*/

#include<bits/stdc++.h>
using namespace std;

void printMap(unordered_map<int, string> &m){
    cout << m.size() << endl;
    for(auto it=m.begin();it!=m.end();++it){  // O(NlogN)
        cout << (it->first) << " " << (it->second) << endl; // printed in sorted order
    }
}

int main(){


    unordered_map<int, string> m;
    m[1] = "a";   
    m[5] = "bb";
    m[3] = "abc";
    m.insert({4,"adf"});
    m[6]; 

    cout << m[6] << endl;
    
    cout << "Find:\n";
    // auto it = m.find(5); // O(1)
    // if(it == m.end()){
    //     cout << "No value\n";
    // }
    // else{
    //     cout << (it->first) << " " << (it->second) << endl;
    // }
    printMap(m);

    cout << "Erase:\n";
    // erase takes either key or iterator input
   /* m.erase(3); // taking key
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
    */
}