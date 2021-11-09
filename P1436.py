def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    nlist = []
    num = 0
    while len(nlist) <= 10000:
        if not num % 10 == 6:
            nlist.append(num * 1000 + 666)
        elif (num // 10) % 100 == 66:
            for k in range(1000):
                nlist.append(num * 1000 + k)
        elif (num // 10) % 10 == 6:
            for j in range(100):
                nlist.append(num * 1000 + 600 + j)
        elif num % 10 == 6:
            for i in range(10):
                nlist.append(num * 1000 + 660 + i)
        num += 1
    print(nlist[n - 1])
solution()