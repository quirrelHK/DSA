'''
Convert the given matrix into a lower triangular matrix. 
 
Example 1 
Input: 4 4 -> Number of rows and columns 
1 2 3 4 
5 6 7 8 
9 8 7 6 
5 4 3 2 
 
Output: 
1 0 0 0 
5 6 0 0 
9 8 7 0 
5 4 3 2 
'''

def solve(matrix,n,m):
    for i in range(n):
        for j in range(m-1,i,-1):
            matrix[i][j] = 0

if __name__ == '__main__':
    matrix = []
    n,m = list(map(int,input().split()))
    
    for _ in range(n):
        lst = list(map(int,input().split()))
        matrix.append(lst[:])
    
    solve(matrix,n,m)
    for i in range(n):
        for j in range(m):
            print(matrix[i][j], end=" ")
        print()