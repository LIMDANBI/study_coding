N, K = map(int, input().split())
Ai = list(map(int, input().split()))
sum = 0
for i in Ai:
    if i%2 == 0:
        sum += i//2
    else:
        sum = sum + i//2 + 1
if sum>=N:
    print("YES")
else:
    print("NO")