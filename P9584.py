def solution():
    import sys
    input = sys.stdin.readline
    code = input()
    N = int(input())
    ans = []
    for i in range(N):
        tmp = input().rstrip()
        is_ok=True
        for j in range(len(tmp)):
            if code[j]!='*' and code[j]!=tmp[j]:
                is_ok = not is_ok
                break
        if is_ok:
            ans.append(tmp)
    print(len(ans))
    for i in ans: print(i)
solution()