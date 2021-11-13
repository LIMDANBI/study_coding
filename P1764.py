def solution():
    import sys
    n, m = map(int, sys.stdin.readline().split())
    li = sys.stdin.read().splitlines()
    heard, saw = set(li[:n]), set(li[n:])
    ans = list(heard & saw)
    ans.sort()
    print(len(ans))
    for i in range(len(ans)): print(ans[i])
solution()