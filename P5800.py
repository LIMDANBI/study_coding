def solution():
    import sys
    input = sys.stdin.readline
    k = int(input())
    for i in range(k):
        score = list(map(int, input().split()))[1:]
        score.sort()
        min_score, max_score, Lgap = min(score), max(score), 0
        for j in range(len(score)-1):
            if Lgap<score[j+1]-score[j]:
                Lgap = score[j+1]-score[j]
        print('Class', i+1)
        print('Max {0}, Min {1}, Largest gap {2}'.format(max_score, min_score, Lgap))
solution()