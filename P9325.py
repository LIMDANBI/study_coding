def solution():
    import sys
    T = int(input())
    for i in range(T):
        s = int(sys.stdin.readline().rstrip())
        n = int(sys.stdin.readline().rstrip())
        for j in range(n):
            q, p = map(int, sys.stdin.readline().rstrip().split())
            s+=q*p
        print(s)
solution()