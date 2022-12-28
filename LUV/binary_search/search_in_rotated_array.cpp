// Array do not contain any duplicates
/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

int find_in_rotated(vector<int> &nums, int target){
    int n = nums.size();
    int lo = 0, hi = n-1;

    // Find the real starting index
    while(hi - lo > 1){
        int mid = lo + (hi-lo)/2;
        if(nums[mid] > nums[hi]){
            lo=mid+1;
        }
        else{
            hi = mid;
        }
    }

    int start = (nums[lo] < nums[hi]) ? lo : hi;  // Real starting index of the array

    // Find whether the target is to the left or to the right of starting index
    lo=0,hi=n-1;
    if(target >= nums[start] && target <= nums[hi]){
        lo=start;
    }
    else{
        hi=start;
    }

    // Now normal binary search
    while(hi - lo >1){
        int mid = lo + (hi-lo)/2;

        if(nums[mid] < target){
            lo = mid+1;
        }
        else{
            hi=mid;
        }
    }

    if(nums[lo]==target) return lo;

    if(nums[hi] == target) return hi;

    return -1;
}

int main(){
    int n,target;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cin >> target;
    int ind = find_in_rotated(nums,target);
    cout << ind << " " << ((ind!=-1)?nums[ind]:-1) << endl;

}