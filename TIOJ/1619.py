from functools import reduce
n=input()
print(reduce(lambda x,y:x*y,map(lambda x,y:x+y,sorted(map(int,input().split()),reverse=1),sorted(map(int,input().split())))))
