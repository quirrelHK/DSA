print('Name: Abhay Singh Bisht')
print('University Roll No: 2061751')
print('Sec: A')
print('Roll NO: 1')
print()
size = 4
string = list(map(int,input('Enter the string: ').split()))
ds = []
hit = miss = 0

for i in range(len(string)):
    if string[i] not in ds:
        if(len(ds) ==  size):
            ds.pop(0)
            ds.append(string[i])
        else:
            ds.append(string[i])
        miss += 1
    else:
        ds.remove(string[i])
        ds.append(string[i])
        hit += 1

print(f'Miss ratio: {miss/(miss+hit):.4f}')
print(f'Hit ratio: {hit/(miss+hit):.4f}')
