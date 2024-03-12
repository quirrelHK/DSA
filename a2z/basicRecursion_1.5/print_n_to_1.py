def print_n_to_1(num):
    if num == 0:
        return
    print(num,end=' ')
    print_n_to_1(num-1)
    
num = 10
print_n_to_1(num)