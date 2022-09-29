N = int(input())
Arr = [0]*(N+6)
Arr[3] = Arr[5] = 1
for i in range(3,N+1):
    if Arr[i]>0:
        if Arr[i+3] == 0:
            Arr[i+3] += (Arr[i]+1)
        if Arr[i+5] == 0:
            Arr[i+5] += (Arr[i]+1)
if Arr[N]!=0:
    print(Arr[N])
else:
    print(-1)