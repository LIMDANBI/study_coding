N, M = map(int, input().split())
trees = list(map(int, input().split()))
begin, end = 0, max(trees)
while begin<=end:
    mid = (begin+end)//2
    cutoff=0
    for i in trees:
        if i>mid:
            cutoff += i-mid
    if cutoff>=M:
        begin=mid+1
    else:
        end=mid-1
print(end)