def solution():
    import sys
    input = sys.stdin.readline
    while(1):
        l, w, h, v = list(map(int, input().rstrip().split()))
        if l==0 and w==0: break
        if l==0: print(v//(w*h), w, h, v)
        elif w==0: print(l, v//(l*h), h, v)
        elif h==0: print(l, w, v//(l*w), v)
        else: print(l, w, h, l*w*h)
solution()