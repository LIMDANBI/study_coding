def solution():
    import sys
    input = sys.stdin.readline
    size1, size2 = map(int, input().split())
    li1 = list(map(int, input().split()))
    li2 = list(map(int, input().split()))
    idx1, idx2 = 0, 0
    while True:
        if idx1<size1 and idx2<size2:
            if li1[idx1] < li2[idx2]:
                print(li1[idx1], end=' ')
                idx1+=1
            else:
                print(li2[idx2], end=' ')
                idx2+=1
        else:
            while(idx1<size1):
                print(li1[idx1], end=' ')
                idx1 += 1
            while(idx2<size2):
                print(li2[idx2], end=' ')
                idx2 += 1
            break
solution()