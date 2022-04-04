def solution():
    import sys
    input = sys.stdin.readline
    N = int(input())
    for i in range(N):
        s = input().rstrip()
        s = s[0].upper() + s[1:]
        print(s)
solution()