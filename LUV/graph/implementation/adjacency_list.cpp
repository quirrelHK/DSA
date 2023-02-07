// Space complexity: O(V+E); (V+E) will generally be less than 10^8
// because at max we can have V^2 edges for V vertices. This means if 
// V = 10^3 then E will be given such that (V+E) does not exceed 10^8.
// So, we can actually store V = 10^5 vertices

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> graph[N];    // Each vector has a list of size N
int main(){
    int n,m;
    cin >> n >>m;
    for(int i=0;i<m;++i){
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

} 