def solution():
    import sys
    input = sys.stdin.readline
    T = int(input())
    for i in range(T):
        n = int(input())
        wn = [((k+1)*(k+2))//2*k for k in range(1,n+1)]
        print(sum(wn))
solution()