#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i =0;i<n;++i){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());

    int find;
    cin >> find;
    int f = 0,r = n-1;
    while(r-f > 1){
        int mid = f + (r-f)/2;

        if(nums[mid] < find){
            f=mid+1;
        }
        else{
            r=mid;
        }
    }

    if(nums[f]==find){
        cout << f << endl;
    }
    else if(nums[r]==find){
        cout << r << endl;
    }
    else{
        cout << "Not found" << endl;
    }
}