'''
Given a number n, print all primes smaller than or equal to n.  
 
Example 1 
Input: 10 
Output: 2 3 5 7 
'''

n = int(input())
is_prime = [True]*(n+1)
is_prime[0] = is_prime[1] = False

for i in range(2,n+1):
    if is_prime[i]:
        for j in range(i+i,n+1,i):
            is_prime[j] = False
        
for i in range(2,n+1):
    if is_prime[i]:
        print(i, end=" ")
        
