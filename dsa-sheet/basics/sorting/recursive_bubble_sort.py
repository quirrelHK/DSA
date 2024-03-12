def bubble_sort(arr,n):
    if n == 1:
        return
    
    for i in range(n-1):
        if arr[i] > arr[i+1]:
            arr[i],arr[i+1] = arr[i+1],arr[i]
            
    bubble_sort(arr,n-1)
    
    
if __name__ == '__main__':
    lst = list(map(int, input().split()))
    
    bubble_sort(lst,len(lst))
    print(lst)