// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int parent[N];
int size_gr[N];
multiset<int> sizes;

void make(int a){
	parent[a]=a;
	size_gr[a]=1;
    sizes.insert(1);
}

int find(int a){
	if(parent[a]==a) return a;

	return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    sizes.erase(sizes.find(size_gr[a]));
    sizes.erase(sizes.find(size_gr[b]));

    sizes.insert(size_gr[a]+size_gr[b]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(size_gr[a] < size_gr[b]){
			swap(a,b);
		}
		parent[b]=a;
        merge(a,b);
		size_gr[a] += size_gr[b];
	}
}
int main() {
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		make(i);
	}

	while(q--){
		int a,b;
		cin >> a >> b;
		Union(a,b);
        if(sizes.size()==1){
            cout << 0 << endl;
        }
        else{
            cout << *(--sizes.end()) - *(sizes.begin()) << endl;
        }
	}
	
}