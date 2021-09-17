level = list(map(int, input().split()))
level.sort()
print(abs(level[3]+level[0]-level[2]-level[1]))