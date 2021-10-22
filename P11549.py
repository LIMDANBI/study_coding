def solution():
    import sys
    input = sys.stdin.readline
    T = int(input())
    response = list(map(int, input().split()))
    ans = 0
    for i in response:
        if T==i: ans+=1
    print(ans)
solution()