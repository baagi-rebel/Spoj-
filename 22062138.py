def modulo(s,x):
    y=0
    l=len(s)
    for i in range(0,l):
        y=((y*10)+ord(s[i])-48)%x
    return y
        
for _ in range(int(input())):
    s=input()
    l=len(s)
    x=1
    for i in range(1,l):
        x=(x*10)%1000000007
    result=modulo(s,1000000007)
    res=result
    for i in range(0,l-1):
        result=(((result-(ord(s[i])-48)*x)*10)+(ord(s[i])-48))%1000000007
        res=(res*x*10+result)%1000000007
    print((res)%1000000007)