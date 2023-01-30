lst = list(map(int,input().split()))
val1,val2,val3 = lst[0]+lst[1],lst[0]+lst[1],lst[1]+lst[2]
if (val1 > 0 and not val1%2) or (val2 > 0 and not val2%2) or(val3 > 0 and not val3%2):
    print('YES')
else:
    print('NO')