while 1:
    a,b,c =input().split()
    a=int(a);c=int(c);
    if a==0 and c==0 : break
    if b=='+': print(a+c)
    elif b=='-': print(a-c)
    elif b=='*': print(a*c)
    else :
        print(a//c,end='');print("...",end='');print(a%c)
