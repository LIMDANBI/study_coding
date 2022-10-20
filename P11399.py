N = int(input())
pi = list(map(int, input().split()))
pi.sort()
sum = 0
k = 0
for i in pi:
    k += i
    sum+=k
print(sum)