def solution():
    import sys, heapq
    input = sys.stdin.readline
    T = int(input())
    for _ in range(T):
        k = int(input())
        size = 0
        sync = [False for _ in range(1000001)]
        min_heap, max_heap = [], []
        for i in range(k):
            operator, number = input().rstrip().split()
            number = int(number)
            if operator == 'I':
                size+=1
                heapq.heappush(min_heap, (number, i))
                heapq.heappush(max_heap, (-number, i))
            else:
                if size != 0:
                    size-=1
                    if number == -1:
                        sync[heapq.heappop(min_heap)[1]] = True
                    else:
                        sync[heapq.heappop(max_heap)[1]] = True
            while len(min_heap) and sync[min_heap[0][1]]: heapq.heappop(min_heap)
            while len(max_heap) and sync[max_heap[0][1]]: heapq.heappop(max_heap)
        if size==0: print("EMPTY")
        else:
            print(-max_heap[0][0], min_heap[0][0])
solution()