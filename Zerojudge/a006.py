a,b,c=map(int,input().split())
if b**2-4*a*c>0:
    r1=((-1*b)+(b**2-4*a*c)**(1/2))/(2*a)
    r2=((-1*b)-(b**2-4*a*c)**(1/2))/(2*a)
    if r1>r2:
        pass
    else :n=r1;r1=r2;r2=n
    print("Two different roots x1={} , x2={}".format(str(int(r1)),str(int(r2))))
elif b**2-4*a*c==0:
    r1=((-1*b)+(b**2-4*a*c)**(1/2))/(2*a)
    print("Two same roots x={}".format(str(int(r1))))
else:
    print("No real root")
