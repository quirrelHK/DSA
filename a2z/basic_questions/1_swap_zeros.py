'''
A chocolate factory is packing chocolates into the packets. The chocolate packets here represent an
array of N number of integer values. The task is to find the empty packets(0) of chocolate and push it
to the end of the conveyor belt(array).
Example 1:
N=8 and arr = [4,5,0,1,9,0,5,0].
There are 3 empty packets in the given set. These 3 empty packets represented as 0 should be
pushed towards the end of the array.
Input:
8 – Value of N
[4,5,0,1,9,0,5,0] – Element of arr[0] to arr[N-1], while input each element is separated by newline
Output: 4 5 1 9 5 0 0 0
'''

# Ordering is preserved after rearrangement
lst = list(map(int,input().split()))
n = len(lst)

i,j = -1,0

while j < n:
    if lst[j] != 0:
        i +=1
        lst[i],lst[j] = lst[j],lst[i]
        
    j += 1
    
print(lst)