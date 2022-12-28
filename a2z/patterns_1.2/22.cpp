/*
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=4;
    int cnt=0;
    for(int i=0;i<n;++i){
        int temp=n;
        cnt=i;
        for(int j=0;j<n;++j){
            cout << temp <<" ";
            if(cnt){
                --temp;
                --cnt;
            }
        }
        cnt=temp-1;
        for(int j=1;j<n;++j){  
            if(cnt==0){
                temp++;
            }
            cout << temp <<" ";
            if(cnt==j){
                temp++;
                cnt++;
            }
        }


        cout<<endl;
    }
    for(int i=n-2;i>=0;--i){
        int temp=n;
        cnt=i;
        for(int j=n;j>=0;--j){
            cout << temp << " ";
            if(cnt){
                temp--;
                cnt--;
            }
        }
        cnt=temp-3;
        for(int j=0;j<n-2;++j){
            if(i==n-2){ 
                temp++;
                cout << temp << " ";
                continue;
            }
            cout << temp <<" ";
            if(cnt==j){
                temp++;
                cnt++;
            }
        }
        cout<<endl;
    }
}
