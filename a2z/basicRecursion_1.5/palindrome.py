def isPalin(string,f,r)->bool:
    if f <= r:
        if string[f]!=string[r]:
            return False
        isPalin(string,f+1,r-1)
    return True

s='madam'
print(isPalin(s,0,len(s)-1))