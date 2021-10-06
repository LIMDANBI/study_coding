def solution():
    N = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    ans = 1
    for i in range(N):
        if ans<nums[i]: break
        ans+=nums[i]
    print(ans)
solution()