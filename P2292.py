def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    ans, cnt = 1, 6
    while 0<n-1:
        n-=cnt
        cnt+=6
        ans+=1
    print(ans)
solution()