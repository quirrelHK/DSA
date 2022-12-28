# consider the following reference string: 
# 0,2,1,6,4,0,3,1,2,1 using FIFO page replacement algorithm (frame size 4)

# string = [0,2,1,6,4,0,3,1,2,1]
print('Name: Abhay Singh Bisht')
print('University Roll No: 2061751')
print('Sec: A')
print('Roll NO: 1')
print()
frame_size = 5
string = list(map(int,input('Enter the string: ').split()))
ds = []
hit = miss = 0
for i in range(len(string)):
    if string[i] not in ds:
        if len(ds) == frame_size:
            ds.pop(0)
        ds.append(string[i])
        miss+=1
    else:
        hit +=1

print(f'Miss ratio: {miss/(miss+hit):.4f}')
print(f'Hit ratio: {hit/(miss+hit):.4f}')

    

    
