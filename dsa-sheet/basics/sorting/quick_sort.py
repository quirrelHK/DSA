def partition(arr,lo,hi):
    pivot = arr[lo]
    i = lo
    j = hi
    while i < j:
        
        while arr[i] <= pivot and i <= hi-1: # First element that is larger than pivot
            i+=1

        while arr[j] > pivot and j >= lo+1: # First element that is smaller than pivot
            j-=1
        
        if i < j:
            arr[i],arr[j] = arr[j],arr[i]
    
    arr[lo],arr[j] = arr[j],arr[lo]
    return j

def quick_sort(arr,lo,hi):
    
    if lo < hi:
        p_ind = partition(arr,lo,hi)
        
        quick_sort(arr,lo,p_ind-1)
        quick_sort(arr,p_ind+1,hi)
        
        
if __name__ == '__main__':
    lst = list(map(int,input().split()))
    
    lo=0
    hi=len(lst)-1
    quick_sort(lst,lo,hi)
    print(lst)
        