def solution():
    import sys
    input = sys.stdin.readline
    n = int(input())
    nlist = []
    mum = 0
    while len(nlist) <= 10000:
        if not mum % 10 == 6:
            nlist.append(mum * 1000 + 666)

        elif (mum // 10) % 100 == 66:
            for k in range(1000):
                nlist.append(mum * 1000 + k)

        elif (mum // 10) % 10 == 6:
            for j in range(100):
                nlist.append(mum * 1000 + 600 + j)

        elif mum % 10 == 6:
            for i in range(10):
                nlist.append(mum * 1000 + 660 + i)
        mum += 1
    print(nlist[n - 1])
solution()