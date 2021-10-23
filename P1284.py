def solution():
    import sys
    input = sys.stdin.readline
    while(1):
        n = input().rstrip()
        if n=="0": break
        else:
            ans = 1
            for i in n:
                if i=='0': ans+=4
                elif i=='1': ans+=2
                else: ans+=3
                ans+=1
            print(ans)
solution()