import random
def bubbleSort(arr,n):
    if n==1:
        return

    flag = False
    for i in range(0,n-1):
        flag = True
        if arr[i] > arr[i+1]:
            arr[i],arr[i+1]=arr[i+1],arr[i]

    if not flag:
        return
    bubbleSort(arr,n-1)

arr = [random.randint(-50,50) for x in range(100)]
bubbleSort(arr,len(arr))
print(arr)
