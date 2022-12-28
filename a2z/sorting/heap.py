import random
def heapify(arr, i, n):
    l = 2*i+1
    r = 2*i+2
    largest = i
    if l < n and arr[largest] < arr[l]:
        largest = l
    if r < n and arr[largest] < arr[r]:
        largest = r
    if largest != i:
        arr[largest],arr[i]=arr[i],arr[largest]
        heapify(arr,largest,n)

def heapsort(arr, n):
    for i in range(n//2-1,-1,-1):
        heapify(arr,i,n)
    
    for i in range(n-1,0,-1):
        arr[0],arr[i]=arr[i],arr[0]
        heapify(arr,0,i)

arr = [random.randint(-50,50) for x in range(100)]

heapsort(arr,len(arr))
print(arr)