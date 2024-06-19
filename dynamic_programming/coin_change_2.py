# We are given an array Arr with N distinct coins and a target. 
# We have an infinite supply of each coin denomination. 
# We need to find the number of ways we sum up the coin values to give us the target.

# Each coin can be used any number of times.


def solve(ind, amt, coins, dp):
    
    if ind == 0:
        return 1 if amt % coins[0] == 0 else 0
    
    if dp[ind][amt] != -1:
        return dp[ind][amt]
    
    not_taken = solve(ind-1, amt, coins, dp)
    
    taken = 0
    if coins[ind] <= amt:
        taken = solve(ind, amt-coins[ind], coins, dp)
        
    dp[ind][amt] = not_taken+taken
    return dp[ind][amt]


if __name__ == "__main__":
    amount = int(input())
    coins = list(map(int, input().split()))
    
    n = len(coins)
    dp = [[-1]*(amount+1) for _ in range(n)]
    
    solve(n-1, amount, coins, dp)
    print(dp[n-1][amount])