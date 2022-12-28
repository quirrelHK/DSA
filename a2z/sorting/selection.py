def bubbleSort(arr):
    for i in range(0,len(arr)-1):
        mini = i
        for j in range(i+1,len(arr)):
            if arr[j] < arr[mini]:
                mini = j
        arr[i],arr[mini]=arr[mini],arr[i]


arr = [3,4,5,6,2,0,5,6,7,8,2,3,4,6,7]
bubbleSort(arr)
print(arr)