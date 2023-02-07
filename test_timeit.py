from timeit import timeit
import_module = 'import math'
s = '''
N = int(5e6+10)
isPrime = [True]*N
isPrime[0]=isPrime[1]=False
for i in range(2,int(math.sqrt(N)+1)):
    if isPrime[i]:
        isPrime[i*2::i] = [False]*len(isPrime[i*2::i])
'''
t = '''
N = int(5e6+10)
isPrime = [True]*N
isPrime[0]=isPrime[1]=False
for i in range(2,int(math.sqrt(N)+1)):
    if isPrime[i]:
        isPrime[i*2::i] = [False for _ in range(2*i,N,i)]
'''
p = '''
N = int(5e6+10)
isPrime = [True]*N
isPrime[0]=isPrime[1]=False
for i in range(2,int(math.sqrt(N)+1)):
    if isPrime[i]:
        for j in range(2*i,N,i):
            isPrime[j]=False
'''

print(timeit(stmt=s, setup=import_module,number=50))
print(timeit(stmt=t, setup=import_module,number=50))
print(timeit(stmt=p, setup=import_module,number=50))
