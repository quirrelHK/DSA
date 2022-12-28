# Randomized
import random
def randomizedPartition(arr,l,r):
    i = random.randint(l,r-1)
    arr[i],arr[r]=arr[r],arr[i]
    x = arr[r]
    i=l-1
    for j in range(l,r):
        if arr[j] <= arr[r]:
            i+=1
            arr[i],arr[j]=arr[j],arr[i]
    i+=1
    arr[i],arr[r]=arr[r],arr[i]
    return i

def quickSort(arr,l,r):
    if l < r:
        mid = randomizedPartition(arr,l,r)

        quickSort(arr,l,mid-1)
        quickSort(arr,mid+1,r)

arr = [random.randint(-50,50) for x in range(100)]

quickSort(arr,0,len(arr)-1)
print(arr,len(arr))