// Using kruskal's algorithm

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int parent[N];
int size_gr[N];

void make(int a){
	parent[a]=a;
	size_gr[a]=1;
}

int find(int a){
	if(parent[a]==a) return a;

	return parent[a] = find(parent[a]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(size_gr[a] < size_gr[b]){
			swap(a,b);
		}
		parent[b]=a;
		size_gr[a] += size_gr[b];
	}
}
int main() {
	int n,e;
    cin >> n >> e;
    
    vector<pair<int, pair<int,int>>> edges;   // pair<weight, pair<edgeU,edgeV>> 
	for(int i=0;i<e;++i){
        int wt,u,v;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});
        // edges.push_back({wt,{v,u}});
    }



    // ********* MST *************
    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;++i){
        make(i);
    }

    int total_cost=0;
    for(auto &edge:edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(find(u)==find(v)){  // If picking this edge makes cycles
            continue;
        }
        Union(u,v);
        total_cost+=wt;
        cout << u << " " << v << endl;
    }

    cout << total_cost << endl;

	
}