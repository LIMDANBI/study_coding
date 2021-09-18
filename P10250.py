import math
T = int(input())
for i in range(T):
    H, W, N = map(int, input().split())
    if N%H:
        floor = N%H
    else:
        floor = H
    arc = math.ceil(N/H)
    if arc//10:
        print(str(floor)+str(arc))
    else:
        print(str(floor)+'0'+str(arc))