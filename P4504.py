def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    while(1):
        tmp = int(input())
        if tmp==0: break
        else:
            if tmp%n==0: print("%d is a multiple of %d."%(tmp, n))
            else: print("%d is NOT a multiple of %d."%(tmp, n))
solution()