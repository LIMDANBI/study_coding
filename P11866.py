N, K = map(int, input().split())
round_table = list(range(1, N+1))
idx=0
print('<', end='')
while len(round_table)!=0:
    if len(round_table)!=N:
        print(', ', end='')
    idx = (idx + K - 1) % len(round_table)
    print(round_table.pop(idx), end='')
print('>', end='')