'''
A furnishing company is manufacturing a new collection of curtains. The curtains are of two colours 
aqua(a) and black (b). The curtains colour is represented as a string(str) consisting of a’s and b’s of 
length N. Then, they are packed (substring) into L number of curtains in each box. The box with the 
maximum number of ‘aqua’ (a) colour curtains is labelled. The task here is to find the number of 
‘aqua’ colour curtains in the labelled box. 
 
*Note: If ‘L’ is not a multiple of N, the remaining number of curtains should be considered as a 
substring too. In simple words, after dividing the curtains in sets of ‘L’, any curtains left will be 
another set(refer example 1) 
 
Example 1 
Input: bbbaaababa -> Value of str 
3    -> Value of L 
 
Output: 3   -> Maximum number of a’s 
 
Explanation: From the input given above. 
Dividing the string into sets of 3 characters each  
Set 1: {b,b,b} 
Set 2: {a,a,a} 
Set 3: {b,a,b} 
Set 4: {a} -> leftover characters also as taken as another set 
Among all the sets, set 2 has more number of a’s. The number of a’s in set 2 is 3. 
Hence, the output is 3
'''

def solve(strs,size):
    res = 0
    for i in range(0,len(strs)):
        cnt = 0
        substr = ""
        for j in range(i,i+size):
            if j == len(strs):
                break
            if strs[j] == "a":
                cnt += 1
            substr += strs[j]
            
        if len(substr) == size:
            res = max(cnt,res)
            
    return res
            

if __name__ == '__main__':
    strs = input()
    size = int(input())
    
    res = solve(strs,size)
    print(res)