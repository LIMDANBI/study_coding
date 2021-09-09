def binarySearch(x):
    low, high = 0, len(list_N)-1
    mid = (low+high)//2
    while low <= high:
        if x == list_N[mid]:
            return mid
        elif x < list_N[mid]:
            high = mid-1
            mid = (low+high)//2
        else:
            low = mid+1
            mid = (low+high)//2
    return -1

N = int(input())
list_N = list(map(int, input().split()))
list_N.sort()
M = int(input())
list_M = list(map(int, input().split()))

for i in list_M:
    if binarySearch(i) == -1:
        print(0)
    else:
        print(1)