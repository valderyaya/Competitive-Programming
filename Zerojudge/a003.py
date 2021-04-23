x=input().split()
y=[int(i) for i in x]
s=(y[0]*2 +y[1])%3
if s==0:
    print("普通")
elif s==1:
    print("吉")
else :
    print("大吉")
