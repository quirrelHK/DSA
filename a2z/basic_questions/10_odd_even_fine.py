'''
Particulate matters are the biggest contributors to Delhi pollution. The main reason behind the 
increase in the concentration of PMs include vehicle emission by applying Odd Even concept for all 
types of vehicles. The vehicles with the odd last digit in the registration number will be allowed on 
roads on odd dates and those with even last digit will on even dates. 
 
Given an integer array a[], contains the last digit of the registration number of N vehicles traveling on 
date D(a positive integer). The task is to calculate the total fine collected by the traffic police 
department from the vehicles violating the rules. 
 
*Note: For violating the rule, vehicles would be fined as X Rs. 
 
Example 1 
Input: 4 -> Value of N 
{5,2,3,7} -> a[], Elements a[0] to a[N-1], during input each element is separated by a new line 
12 -> Value of D, i.e. date  
200 -> Value of x i.e. fine 
 
Output: 600 -> total fine collected  
 
Explanation: Date D=12 means, only an even number of vehicles are allowed.  
Find will be collected from 5,3 and 7 with an amount of 200 each. 
Hence, the output = 600.
'''

def solve(cars,date,x):
    
    even_cnt = 0
    for car in cars:
        if car%2 == 0:
            even_cnt += 1
        
    if date%2 == 0:
        num_fines = len(cars) - even_cnt
    else:
        num_fines = even_cnt
    
    return num_fines*x

if __name__ == '__main__':
    cars = list(map(int,input().split()))
    date = int(input())
    x = int(input())
    
    res = solve(cars,date,x)
    print(res)