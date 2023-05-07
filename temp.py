def solve(A, B):
        n=len(A)
        preSum=[0]*n
        preSum[0]=A[0]
        for i in range(1,n):
            preSum[i]=preSum[i-1]+A[i]
        res=[-1]*n
        print(preSum)
        return
        for i in range(n):
            cnt=0
            f=0
            while f < n and preSum[f]<B[i]:
                f+=1
            if f < n and preSum[f]>=B[i]:
                res[i]=f+1
                
            if res[i] == -1 and preSum[-1] >0:
                cur=preSum[-1]
                cnt=n
                f=0
                while cur < B[i]:
                    cur+=preSum[f]
                    cnt+=1
                    f+=1
                    if f == n:
                        f=0
                res[i]=cnt
                
        return res
                
                
       
        
# lst1=[7,-15,19,-15,-11,1,17,5,-18]
# lst2=[28,22,23,12,56,23,45,12,45]
# lst1=[1,2,1]
# lst2=[10,2,3]
lst1=list(map(int,input().split()))
lst2=list(map(int,input().split()))

# lst1=[11,18,0,0,-13,-1,1]
# lst2=[10,25,29,38,5,36,38]

print(solve(lst1,lst2))
        
        