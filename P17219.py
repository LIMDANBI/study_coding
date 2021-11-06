def solution():
    import sys
    input = sys.stdin.readline
    n, m = map(int, input().split())
    dict = {}
    for i in range(n):
        site, password = input().rstrip().split()
        dict[site] = password
    for i in range(m):
        site = input().rstrip()
        print(dict[site])
solution()