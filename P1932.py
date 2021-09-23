import sys
n = int(input())
tri = [list(map(int, sys.stdin.readline().rstrip().split())) for i in range(n)]
for i in range(n-2, -1, -1):
    for j in range(i+1):
        tri[i][j]+=(max(tri[i+1][j] ,tri[i+1][j+1]))
print(tri[0][0])