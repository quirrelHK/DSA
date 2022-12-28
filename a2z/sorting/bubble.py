def bubbleSort(arr):
    for i in range(len(arr)):
        flag=False
        for j in range(0,len(arr)-1-i):
            flag=True
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
        if not flag:
            break

arr = [2, 3, 4, 5, 0, 5, 2, 3, 6, 7, 6, 4, 6, 7, 8]
bubbleSort(arr)
print(arr)