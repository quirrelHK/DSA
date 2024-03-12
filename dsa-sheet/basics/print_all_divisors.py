def find_divisors(num):
    lst = []
    for divisor in range(1,int(num**0.5)+1):
        if num%divisor == 0:
            lst.append(int(divisor))
            if divisor != num/divisor:
                lst.append(int(num/divisor))
    return lst

if __name__ == '__main__':
    num = int(input())
    res = find_divisors(num)
    print(res)