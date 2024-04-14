'''Joseph is learning digital logic subject which will be for his next semester. He usually tries to solve
unit assignment problems before the lecture. Today he got one tricky question. The problem
statement is “A positive integer has been given as an input. Convert decimal value to binary
representation. Toggle all bits of it after the most significant bit including the most significant bit.
Print the positive integer value after toggling all bits”.
Constrains:
1<=N<=100
Example 1:
Input: 10 -> Integer'''

num = int(input())
temp = num

k = 0
while temp:
    temp >>= 1
    k = (k << 1) +1
    
print(~num & k)

