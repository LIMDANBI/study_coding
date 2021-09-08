N, M = map(int, input().split())
card = list(map(int, input().split()))
ans = 0
for i in range(len(card)):
    for j in range(i+1, len(card)):
        for k in range(j+1, len(card)):
            if ans < card[i]+card[j]+card[k] <= M:
                ans = card[i]+card[j]+card[k]
print(ans)