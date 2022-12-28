// Lower bound- element or the value greater than element
// Upper bound- the value greater than element

#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &v, int target){
    int lo=0,hi=v.size()-1;

    while(hi - lo > 1){
        int mid = lo + (hi-lo)/2;

        if(v[mid] < target){
            lo = mid+1;
        }
        else{
            hi=mid;
        }        
    }
    cout << lo << ":" << hi << endl;
    if(v[lo] >= target)
        return lo;
    else if(v[hi] >= target)
        return hi;
    return -1;
}

int upperbound(vector<int> &v, int target){
    int lo=0,hi=v.size()-1;

    while(hi - lo > 1){
        int mid = lo + (hi-lo)/2;

        if(v[mid] <= target){
            lo = mid+1;
        }
        else{
            hi=mid;
        }        
    }
    cout << lo << ":" << hi << endl;

    if(v[lo] >= target)
        return lo;
    else if(v[hi] >= target)
        return hi;
    return -1;
}

int main(){
    int n,target;
    cin >> n;
    vector<int> nums(n);

    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cin >> target;
    sort(nums.begin(),nums.end());
    
    
    int lo = lowerbound(nums,target);
    int up = upperbound(nums,target);

    cout << "Lower Bound: " << lo << " " <<  (lo!=-1 ? nums[lo] : -1) << endl;
    cout << "Upper Bound: " << up << " " << (up!=-1 ? nums[up] : -1) << endl;


}