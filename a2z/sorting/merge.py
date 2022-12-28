# Divide and Conqure
# O(NlogN)

def merge(arr,l,r,mid):
    leftArr=[]
    rightArr=[]
    for i in range(mid-l+1):
        leftArr.append(arr[l+i])
    for i in range(r-mid):
        rightArr.append(arr[mid+i+1])
    k=l
    i=j=0
    while i < len(leftArr) and j < len(rightArr):
        if leftArr[i] < rightArr[j]:
            arr[k]=leftArr[i]
            i+=1
        else:
            arr[k]=rightArr[j]
            j+=1
        k+=1
    while i < len(leftArr):
        arr[k]=leftArr[i]
        k+=1
        i+=1
    while j < len(rightArr):
        arr[k]=rightArr[j]
        k+=1
        j+=1
    

def mergeSort(arr,l,r):
    if l < r:
        mid = (l+r)//2
        mergeSort(arr,l,mid)
        mergeSort(arr,mid+1,r)
        merge(arr,l,r,mid)

#[1,2,3,4,5]
arr=[2, 3, 4, 5, 0, 5, 2, 3, 6, 7, 6, 4, 6, 7, 8]
import random
arr = [random.randint(-100,100) for x in range(100)]
mergeSort(arr,0,len(arr)-1)
print(arr,len(arr))
