import random

def insertion(arr,j,n):
    if j==n:
        return
    
    mini=arr[j]
    i=j-1
    while i>=0 and mini <= arr[i]:
        arr[i+1]=arr[i]
        i-=1
    arr[i+1],mini=mini,arr[i+1]

    insertion(arr,j+1,n)

arr = [random.randint(-50,50) for x in range(100)]
insertion(arr,1,len(arr))
print(arr)