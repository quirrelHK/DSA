// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-soldiers/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];


void make(int a){
    parent[a]=a;

}

int find(int a){
    if(parent[a]==a) return a;

    return parent[a] = find(parent[a]);
}

void make_leader(int a){
    int lead = find(a);
    if(lead!=a){
        parent[lead]=a;
        parent[a]=a;
    }
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        parent[a]=b;
    }
}

int main(){
    int n,q;
    cin >> n;
    for(int i=1;i<=n;++i){
        make(i);
    }
    cin >> q;
    while(q--){
        int format,a,b;
        cin >> format;
        switch (format)
        {
        case 1:
            cin >> a >> b;
            Union(a,b);
            break;
        case 2:
            cin >> a;
            make_leader(a);
            break;
        case 3:
            cin >> a;
            cout << find(a) << endl;
        default:
            break;
        }
    }

}