import sys

x=["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]
for s in sys.stdin:
    a=s.strip();b=int(input())
    print(x[(x.index(a)+b)%7])
    

