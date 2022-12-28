def insertionSort(arr):
    for j in range(1,len(arr)):
        mini=arr[j]
        i=j-1
        while i>=0 and arr[i] >= mini:
            arr[i+1]=arr[i]
            i-=1
        arr[i+1]=mini
        

arr=[4, 5, 6, 3, 7, 5, 6, 7, 8, 2, 3, 4, 6, 2, 0]
insertionSort(arr)
print(arr)