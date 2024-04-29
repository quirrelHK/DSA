# Linear time pattern matching algorithm. Finds all the occurrences of pattern P in string S


def z_algorithm(pattern,string):
    string = pattern + "$" + string
    n = len(string)
    l = r = 0
    z = [0]*n
    res = []
    for i in range(1,n):
        
        if r < i:
            l = r = i
            while r < n and string[r-l] == string[r]:
                r += 1
                
            z[i] = r-l
            r-=1
        else:
            k = i-l
            if z[k] < r-i+1:
                z[i] = z[k]
            else:
                l = i
                while r < n and string[r-l] == string[r]:
                    r += 1
                z[i] = r-l
                r-= 1

    for i in range(n):
        if z[i] == len(pattern):
            res.append(i-len(pattern)-1)

    return res
if __name__ == '__main__':
    pattern = input()
    strs = input()
    
    print(z_algorithm(pattern,strs))

