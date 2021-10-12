def solution():
    import sys
    input = sys.stdin.readline
    N, W, H, L = map(int, input().split())
    ans = (W//L)*(H//L)
    if ans <= N: print(ans)
    else: print(N)
solution()