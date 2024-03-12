

def merge(arr,lo,hi,mid):
    left = []   
    right = []
    for i in range(lo,mid+1):
        left.append(arr[i])
    for i in range(mid+1,hi+1):
        right.append(arr[i])
    left.append(float('inf'))
    right.append(float('inf'))
    
    l_ind = r_ind = 0
    for i in range(lo,hi+1):
        if left[l_ind] <= right[r_ind]:
            arr[i] = left[l_ind]
            l_ind += 1
            
        else:
            arr[i] = right[r_ind]
            r_ind+=1
    

def merge_sort(arr,lo,hi):
    if lo >= hi:
        return
    mid = lo + (hi-lo)//2
    merge_sort(arr,lo,mid)
    merge_sort(arr,mid+1,hi)
    merge(arr,lo,hi,mid)
    

if __name__ == '__main__':
    lst = list(map(int,input().split()))
    lo=0
    hi=len(lst)-1
    
    merge_sort(lst,lo,hi)
    print(lst)