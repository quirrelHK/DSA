# Print numbers from 1 to N without the help of loops.

class Solution:    

    def rec(self,i,N):
        if i > N:
            return
        print(i,end=' ')
        self.rec(i+1,N)
        
    def printNos(self,N):
        return self.rec(1,N)

obj=Solution()
obj.printNos(10)