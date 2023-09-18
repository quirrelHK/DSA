class DSU:
    
    def __init__(self,n) -> None:
        self.rank = [0]*(n+1)
        self.parent = [i for i in range(n+1)]
        self.size = [1]*(n+1)
        
     
    def find_parent(self,u):
        if self.parent[u] == u:
            return u
        
        self.parent[u]  = self.find_parent(self.parent[u])
        return self.parent[u]  
    
    def union_by_rank(self,u,v):
        ultimate_u = self.find_parent(u)
        ultimate_v = self.find_parent(v) 
        if ultimate_u == ultimate_v:
            return
        
        if self.rank[ultimate_u] < self.rank[ultimate_v]:
            self.parent[ultimate_u] = ultimate_v
        
        elif self.rank[ultimate_v] < self.rank[ultimate_u]:
            self.parent[ultimate_v] = ultimate_u
        else:
            self.parent[ultimate_v] = ultimate_u
            self.rank[ultimate_u]+=1
            
            
    def union_by_size(self,u,v):
        ultimate_u = self.find_parent(u)
        ultimate_v = self.find_parent(v)
        if ultimate_u == ultimate_v:
            return
        if self.size[ultimate_u] < self.size[ultimate_v]:
            self.parent[ultimate_u] = ultimate_v
            self.size[ultimate_v] += self.size[ultimate_u]
        else:
            self.parent[ultimate_v] = ultimate_u
            self.size[ultimate_u] += self.size[ultimate_v]
        
if __name__ == '__main__':
    disjoint_set = DSU(7)
    disjoint_set.union_by_rank(1,2)
    disjoint_set.union_by_rank(2,3)
    disjoint_set.union_by_rank(4,5)
    disjoint_set.union_by_rank(6,7)
    disjoint_set.union_by_rank(5,6)
    # if 3 and 7 belong to same group of not
    if disjoint_set.find_parent(3) == disjoint_set.find_parent(7):
        print('Same parent')
    else:
        print('Not same parents')
    
    disjoint_set.union_by_rank(3,7)
    if disjoint_set.find_parent(3) == disjoint_set.find_parent(7):
        print('Same parent')
    else:
        print('Not same parents') 
    
            
            