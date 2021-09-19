import sys
N, M = map(int, input().split())
chess = list()
for i in range(N):
    chess.append(sys.stdin.readline().rstrip())
ans = 32
for i in range(N-7):
    for j in range(M-7):
        repaint = 0
        begin_chr=chess[i][j]
        if begin_chr == 'B':
            scnd_chr = 'W'
        else:
            scnd_chr = 'B'
        begin_mod2=(i+j)%2
        for k in range(i, i+8):
            for l in range(j, j+8):
                if (k+l)%2==begin_mod2:
                    if chess[k][l]!=begin_chr:
                        repaint+=1
                else:
                    if chess[k][l]!=scnd_chr:
                        repaint+=1
        ans = min(ans, repaint, 64-repaint)
print(ans)