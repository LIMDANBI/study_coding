N = int(input())
card_pack = list(map(int, input().split()))
dp = [card_pack[0], card_pack[0]]
for i in range(2, N+1):
    tmp=0
    for j in range(1, i//2+1):
        tmp = max(tmp, dp[j]+dp[i-j])
    dp.append(max(tmp, card_pack[i-1]))
print(dp[N])