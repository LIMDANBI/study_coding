def solution():
    import sys
    A, B, V = map(int, sys.stdin.readline().rstrip().split())
    if (V-A)%(A-B)!=0: print((V-A)//(A-B)+2)
    else: print((V-A)//(A-B)+1)
solution()