from functools import cmp_to_key
def cmp(a,b):
    # First decreasing order of 2nd value, then decreasing order of 1st value
    if a[1] != b[1]:
        if a[1] < b[1]: return 1         
        elif a[1] > b[1]: return -1
        return 0  # if both are equal
    else: 
        if a[0] > b[0]: return 1
        elif a[0] < b[0]: return -1
        return 0
lst = []
# n = int(input())

# for i in range(n):
#     lst.append(list(map(int,input().split())))
lst = [(865635090, 18), (934288178, 16), (864052244, 14), (625397331, 10), (686276715, 9), (281613863, 9), (519945877, 8), (971253305, 7), (512505036, 4)]

lst =  sorted(lst,key=cmp_to_key(cmp))
print(lst)