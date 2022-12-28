/*
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/
#include<bits/stdc++.h>
using namespace std;

int find_peak(vector<int> &nums){
    int n = nums.size();
    int lo=0,hi=n-1;

    while(hi-lo>1){
        int mid = lo + (hi-lo)/2;

        // Checking edge cases
        if(mid == 0 && nums[mid] > nums[mid+1]) return 0;

        if(mid == n-1 && nums[mid] > nums[mid-1]) return n-1;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

        else if(nums[mid-1] > nums[mid]){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    if(nums[lo] > nums[hi]) return lo;

    if(nums[hi] > nums[lo]) return hi;

    return -1;
}

int main(){

    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    int ind = find_peak(nums);
    cout << ind << " " << ((ind!=-1)?nums[ind]:-1) << endl;

}