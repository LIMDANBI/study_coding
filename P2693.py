ans = []
T = int(input())
for i in range(T):
    A = list(map(int,input().split()))
    for i in range(2):
        tmp = max(A)
        A.remove(tmp)
    ans.append(max(A))
for i in ans:
    print(i)