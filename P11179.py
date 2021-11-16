def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    binary = []
    while n>1:
        binary.append(n%2)
        n=n//2
    binary.append(n)
    ans = 0
    digit = 1
    for i in range(len(binary)-1, -1, -1):
        ans+=digit*binary[i]
        digit *= 2
    print(ans)
solution()