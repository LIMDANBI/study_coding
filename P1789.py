s = int(input())
n, low, high = 0, 1, s

while low <= high:
    mid = (low+high)//2
    if mid*(mid+1)//2 > s:
        high = mid-1
    else:
        n = mid
        low = mid+1
print(n)