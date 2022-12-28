print('Ritesh Singh\nSec: A\n2060008\n')

n = int(input("Enter number of processes: "))
m = int(input("Enter number of recources: "))

avail = list(map(int,input('Enter available resources: ').split()))

print('Enter Allocation matrix: ')
alloc = [list(map(int,input().split())) for _ in range(n)]

# max_matrix = []
print('Enter MAX matrix: ')
max_matrix = [list(map(int,input().split())) for _ in range(n)]
# for _ in range(n):
#     max_matrix.append(list(map(int,input().split())))



f = [0]*n
ans = [0]*n
ind = 0
    
need = [[ 0 for _ in range(m)]for _ in range(n)]  # Remaining resources need of each element
for i in range(n):
    for j in range(m):
        need[i][j] = max_matrix[i][j] - alloc[i][j]
y = 0
for k in range(n):
    for i in range(n):
        if (f[i] == 0):
            flag = 0
            for j in range(m):
                if (need[i][j] > avail[j]):
                    flag = 1
                    break
            
            if (flag == 0):
                ans[ind] = i
                ind += 1
                for y in range(m):
                    avail[y] += alloc[i][y]
                f[i] = 1
                
print("Following is the SAFE Sequence")

for i in range(n-1):
    print(f'P{ans[i]} -> ',end='')
print(f'P{ans[n-1]}')


