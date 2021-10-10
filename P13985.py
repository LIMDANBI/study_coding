def solution():
    import sys
    input = sys.stdin.readline
    expression, ans = input().split('=')
    a, b = map(int, expression.split('+'))
    if a+b == int(ans): print('YES')
    else: print('NO')
solution()