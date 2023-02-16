#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int num;
        vector<int> pro(n,0);
        int cnt=0;
        for(int i=0;i<n;++i){
            cin >> num;
            if(num==2){
                cnt++;
            }
            pro[i]=cnt;
            
        }  
    
        if(cnt==1){
            cout << -1 << endl;
        }
        else if(cnt==0){
            cout << 1 << endl;
        }
        else{
            bool flag=false;
            for(int i=0;i<n;++i){
                if(pro[i] == pro[n-1]-pro[i]){
                    cout << i+1 << endl;
                    flag=true;
                    break;
                }
            }
            if(!flag)  
                cout << -1 << endl;
        }
    }
}

/*
10
2
1 1
2
2 1
2
1 2
2
2 2
3
1 1 1
3
2 1 1
3
1 2 1
3
2 2 1
3
1 1 2
3
2 1 2
*/