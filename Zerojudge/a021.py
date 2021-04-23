import sys
for i in sys.stdin:
    print(int(eval(i.replace('/','//'))))
