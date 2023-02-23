// https://codeforces.com/contest/1245/problem/D
/*
First we create a graph of cities ignoring the cost of power station and find a minimum spanning tree
for connecting wires between the cities(such that the cost of wires will be minimum).
Now, we also have to make power station, but it may be that building multiple power stations and connecting 
less cities through wire is less costly. So, to tackle this we will introduce a new node to the graph say node zero
Now we connect this node to each city in previous graph and the edge weight being the cost of making power station.
In this new graph we will make a MST and by defintion edges will be choosen such that cost is minimized(i.e. among all the edges
between cities denoting wire cost and between citis and zero node denoting cost of power station; cost will be minimized)
*/

#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;

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
	int n;
    cin >>n;
    vector<pair<int,int>> cities(n+1); // coordinates of cities
    
	for(int i=1;i<=n;++i){
        cin >> cities[i].first >> cities[i].second;
    }

    vector<int> c(n+1),k(n+1);
    for(int i=1;i<=n;++i){
        cin >> c[i];
    }
    for(int i=1;i<=n;++i){
        cin >> k[i];
    }


    vector<pair<long long, pair<int,int>>> edges;
    for(int i=1;i<=n;++i){
        edges.push_back({c[i],{0,i}});  // edges for zero node
    }

    // Now edges between cities
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int dist = abs(cities[i].first-cities[j].first) + abs(cities[i].second-cities[j].second);
            long long cost = dist*1LL*(k[i]+k[j]);

            edges.push_back({cost,{i,j}});
        }
    }

    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;++i){
        make(i);
    }

    vector<int> power_stations;
    vector<pair<int,int>> connections;

    long long total_cost=0;
    for(auto &edge:edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(find(u)==find(v)){  // If picking this edge makes cycles
            continue;
        }
        Union(u,v);
        total_cost+=wt;
        if(u==0 || v == 0){
            power_stations.push_back(max(u,v));  // Non-zero value
        }
        else{
            connections.push_back({u,v});
        }
    }

    cout << total_cost << endl;
    cout << power_stations.size() << endl;
    for(auto station:power_stations){
        cout << station << " ";
    }
    cout << endl;
    cout << connections.size() << endl;
    for(auto connection:connections){
        cout << connection.first << " " << connection.second << endl;
    }

	
}