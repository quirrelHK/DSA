from os import *
from sys import *
from collections import *
from math import *


def merge(arr,lo,hi,mid):
    arr_l = []
    arr_r = []
    for i in range(lo,mid+1):
        arr_l.append(arr[i])
    for j in range(mid+1,hi+1):
        arr_r.append(arr[j])
    arr_l.append(float('inf'))
    arr_r.append(float('inf'))

    cnt = 0
    r_ind = l_ind = 0
    for i in range(lo,hi+1):
        if arr_l[l_ind] <= arr_r[r_ind]:
            arr[i] = arr_l[l_ind]
            l_ind += 1
        else:
            arr[i] = arr_r[r_ind]
            cnt += ((mid-lo+1)-l_ind)
            r_ind += 1

    return cnt


def merge_sort(arr,lo,hi):
    cnt = 0
    if lo >= hi: return cnt

    mid = lo + (hi-lo)//2
    cnt += merge_sort(arr,lo,mid)
    cnt += merge_sort(arr,mid+1,hi)

    cnt += merge(arr,lo,hi,mid)
    return cnt

def getInversions(arr, n) :
	
	return merge_sort(arr,0,n-1)

# Taking inpit using fast I/O.
def takeInput() :
    n = int(input())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n

# Main.
arr, n = takeInput()
print(getInversions(arr, n))
print(arr)