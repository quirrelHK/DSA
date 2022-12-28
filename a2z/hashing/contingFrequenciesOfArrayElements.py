# Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be 
# repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.
# Note: The elements greater than N in the array can be ignored for counting and please read your task sec
# tion of the problem carefully to understand how to output the array.

def frequencyCount(arr, N, P):
    # code here
    mydict={}
    for i in range(N):
        if arr[i] > N:
            continue
        else: mydict[arr[i]] = mydict.get(arr[i],0)+1
    for i in range(N):
        arr[i]=mydict.get(i+1,0)
        
