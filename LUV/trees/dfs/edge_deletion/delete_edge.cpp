// https://www.interviewbit.com/problems/delete-edge/

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int M=1e9+7;
vector<int> graph[N];
int subtree_sum[N];
int val[N]; // Stores the weights assigned to each node

void dfs(int v, int p=-1){
    
    subtree_sum[v] += val[v];
    for(int child:graph[v]){
        if(child==p) continue;

        dfs(child,v);
        subtree_sum[v] += subtree_sum[child];
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
        int wt;
        cin >> wt;
        val[i]=wt;
    }

    for(int i=0;i<n-1;++i){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);
    
    long long res=0;
    for(int i=2;i<=n;++i){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1]-part1;
        res = max(res, (part1 *1LL*part2)%M);
    }

    cout << res << endl;

}