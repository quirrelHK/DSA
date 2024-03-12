def insertion_sort(arr,i,n):
    if i == n-1:
        return
    j = i+1
    while j > 0 and arr[j-1] > arr[j]:
        arr[j-1],arr[j] = arr[j],arr[j-1]
        j-=1
        
    insertion_sort(arr,i+1,n)
    
    
if __name__ == '__main__':
    lst = list(map(int, input().split()))
    
    insertion_sort(lst,0,len(lst))
    print(lst)