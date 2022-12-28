res = []
def generate(s,open,close):
    if open==0 and close==0:
        res.append(s)
        return
    if open>0:
        s+='('
        generate(s,open-1,close)
        s = s[:-1]
    if close>0:
        if open < close:
            s+=')'
            generate(s,open,close-1)
            s = s[:-1]


n=4
generate("",n,n)
for x in res:
    print(x)