// red back tree 
// only one difference between maps and multimaps - you can have duplicate keys in multimaps
#include<bits/stdc++.h>
using namespace std;

void printMap(multimap<int, string> &m){
    cout << "Size:" << m.size() << endl;
    for(auto it=m.begin();it!=m.end();++it){
        cout << (it->first) << " " << (it->second) << endl;
    }
}
int main(){
    multimap<int, string> m;
    m.insert({0,"abc"});
    m.insert({1,"bcb"});
    m.insert({0,"bcb"});
    m.insert({0,"abc"});

    printMap(m);
}