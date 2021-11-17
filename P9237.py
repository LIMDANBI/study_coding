def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    days = list(map(int, input().split()))
    days.sort(reverse=True)
    now, end = 0, 0
    for i in days:
        if end<now+1+i:
            end = now+1+i
        now+=1
    print(end+1)
solution()