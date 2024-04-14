'''
Airport security officials have confiscated several items of the passengers at the security check point.
All the items have been dumped into a huge box (array). Each item possesses a certain amount of
risk[0,1,2]. Here, the risk severity of the items represent an array[] of N number of integer values.
The task here is to sort the items based on their levels of risk in the array. The risk values range from
0 to 2.
Example:
Input: 7 -> Value of N
[1,0,2,0,1,0,2]-> Element of arr[0] to arr[N-1], while input each element is separated by new line.
Output: 0 0 0 1 1 2 2 -> Element after sorting based on risk severity
'''


def solve(nums):
    lo = mid = 0
    hi = len(nums) - 1
    
    while mid <= hi:
        if nums[mid] == 0:
            nums[lo],nums[mid] = nums[mid],nums[lo]
            lo += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:
            nums[hi],nums[mid] = nums[mid],nums[hi]
            hi -= 1
    

if __name__ == '__main__':
    nums = list(map(int,input().split()))

    solve(nums)
    print(nums)