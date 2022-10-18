def solution():
    T = int(input())
    for t in range(T):
        ans = 0
        N, M = map(int, input().split())
        for num in range(N, M+1):
            ans+=str(num).count('0')
        print(ans)
solution()