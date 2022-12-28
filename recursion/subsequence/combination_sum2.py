# def solve(ind, ds, ans, target, candidates):
#     if target == 0:
#         ans.append(ds)
#         print(ans)
#         return
#     for i in range(ind,len(candidates)):
#         if i > ind and candidates[i-1] == candidates[i]:
#             continue
#         if candidates[i] > target:
#             break
#         ds.append(candidates[i])
#         solve(i+1,ds,ans,target-candidates[i],candidates)
#         ds.pop()
# def combinationSum2(candidates, target):
#     ds = []
#     ans = []
    
#     candidates = sorted(candidates)
#     solve(0,ds,ans,target,candidates)
#     print(ans)
#     return ans

# if __name__ == '__main__':
#     lst = [10,1,2,7,6,1,5]
#     target = 8

#     print(combinationSum2(lst,target))
nums=[1,2,3]
ans = 0
nums = sorted(nums)
target=4
def solve(ind, target,ans):
    if target == 0:
        ans=ans+1
        return 
    
    for i in range(ind,len(nums)):
        if target < nums[i]:
            break
            
        if nums[i] <= target:
            l = solve(i,target-nums[i],ans)
    else: 
        r = solve(i+1,target,ans)

    return l+r

solve(0,target,ans)
print(ans)

lst = [1,2,3,4,5]

for i in range(len(lst)):
    print(i)
print(i)

