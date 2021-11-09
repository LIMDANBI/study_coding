def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    cnt, ans = 1, 666
    while cnt!=n:
        ans += 1
        for i in range(len(str(ans))-2):
            if str(ans)[i: i+3] == '666':
                cnt+=1
                break
    print(ans)
solution()