def solution():
    import sys
    input = sys.stdin.readline
    a, b = map(int, input().split())
    if a<b:
        asum, bsum = a*(a-1)//2, b*(b+1)//2
        print(bsum-asum)
    else:
        asum, bsum = a*(a+1)//2, b*(b-1)//2
        print(asum-bsum)
solution()