def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    score = list(map(int, input().split()))
    score.sort()
    print(score[n-1]-score[0])
solution()