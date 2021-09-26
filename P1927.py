def solution():
    import sys
    from queue import PriorityQueue

    input = sys.stdin.readline
    pq = PriorityQueue()
    n = int(input())
    for i in range(n):
        x = int(input())
        if x==0:
            if pq.qsize()==0:
                print(0)
            else:
                print(pq.get())
        else:
            pq.put(x)
solution()