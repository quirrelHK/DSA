#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;

long long dist[N][N];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int wt;
            cin >> wt;
            dist[i][j]=wt;
        }
    }

    vector<int> del_order(n);
    for(int i=0;i<n;++i){
        cin >> del_order[i];
    }

    reverse(del_order.begin(),del_order.end());
    vector<long long> ans;
    for(int k=0;k<n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                long long new_dist = dist[i][del_order[k]] + dist[del_order[k]][j];
                dist[i][j] = min(dist[i][j],new_dist);
            }
        }
        long long sum=0;
        for(int i=0;i<=k;++i){
            for(int j=0;j<=k;++j){
                sum += dist[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto &val:ans)
        cout << val << endl;
}