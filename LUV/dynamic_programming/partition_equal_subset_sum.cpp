// https://leetcode.com/problems/partition-equal-subset-sum/

/*  
    General subset sum:
    We are given a value sum and an array and we need to find a subset for which the sum of its elements are equal 
    to the given sum.

    In this particular problem we need to divide the array into to subset such that the sum of both the subsets is same.
    Since we have to divide array into two subsets, the required sum would be half of the entire sum of the array.
    i.e. the sum of both the part is same then the sum of one part would be sum(array)/2
*/
#include<bits/stdc++.h>
using namespace std;

int dp[205][20005];
bool func(int ind, int sum, vector<int> &nums){

    if(sum == 0) return true;
    if(ind < 0) return false;
    if(dp[ind][sum] != -1) return dp[ind][sum];
    // Not Pick the ith index
    bool isPartition = func(ind-1,sum,nums);

    // Pick the ith index
    if(sum-nums[ind] >= 0){
        isPartition |= func(ind-1,sum-nums[ind],nums);
    }

    return dp[ind][sum] = isPartition;
}
bool canPartition(vector<int>& nums) {
    memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(),nums.end(), 0);

        /* 
            If sum is odd this means we cannot divide the array into 2 halves becuase elements are of type integer
            and so we cannot have decimal sum for a part
         */
        if(sum%2 != 0) return false;
        sum /=2;
        return func(nums.size()-1,sum,nums);
}
int main(){

}