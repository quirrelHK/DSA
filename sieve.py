# import math
# N = int(1e5)+10
# isPrime=[True]*N
# isPrime[0]=isPrime[1]=False
# for i in range(2,int(math.sqrt(N))+1):
#     if isPrime[i]:
#         isPrime[2*i::i] = [False]*len(isPrime[2*i::i])


# for i in range(2,100):
#     print(i,isPrime[i],sep='-',end=' ')

N = int(1e5)+10
isPrime=[True]*N
isPrime[0]=isPrime[1]=False
for i in range(2,N):
    if isPrime[i]:
        isPrime[2*i::i] = [False]*len(isPrime[2*i::i])

print(isPrime)