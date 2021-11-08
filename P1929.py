def solution():
    import sys
    input = sys.stdin.readline
    m, n = map(int, input().split())
    li = [False] + [True] * ((n - 1) // 2)
    for x in range(1, int(n**0.5/2+1)):
        if li[x]:
            li[2 * x * (x + 1)::x * 2 + 1] = [False] * ((((n + 1) // 2) - x * x * 2) // (x * 2 + 1))
    if m <= 2:
        print(2)
    print('\n'.join([f'{x}' for x, val in zip(range(m + (m & 1 == 0), n + 1, 2), li[m // 2:]) if val]))
solution()