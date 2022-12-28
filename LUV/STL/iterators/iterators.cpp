// Some containers like sets do not have indexing. So, we use iterators for accessing elements of such containers
#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v = {2,3,5,6,7};
    
    vector<int> ::iterator it = v.begin();
    cout << *(it+2) << endl;

    // for(it =v.begin();it!=v.end(); ++it){
    //     cout << (*it) << "  ";
    // }

    vector<pair<int,int>> v_p = {{1,2},{3,4},{5,6}};
    vector<pair<int,int>> :: iterator it_p;

    for(it_p=v_p.begin();it_p!=v_p.end();++it_p){
        cout << (*it_p).first << " " << (*it_p).second << endl;
    }
    
    // (*it_p).first == (it_p->first)
    for(it_p=v_p.begin();it_p!=v_p.end();++it_p){
        cout << (it_p->first) << " " << (it_p->second) << endl;
    }
}
