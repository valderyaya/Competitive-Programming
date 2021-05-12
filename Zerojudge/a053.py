x=int(input())
if x>=0 and x<=10:
    print(x*6)
elif x<=20:
    print(60+(x-10)*2)
elif x<=40:
    print(80+(x-20)*1)
else:print(100)
