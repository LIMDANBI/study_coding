import sys
import heapq

input = sys.stdin.readline
pos_heap = []
neg_heap = []

for i in range(int(input())):
    x = int(input())
    if x:
        if(x>0): heapq.heappush(pos_heap, x)
        else: heapq.heappush(neg_heap, -x)
    else:
        if len(pos_heap) and len(neg_heap):
            if abs(pos_heap[0])>=abs(neg_heap[0]): print(-heapq.heappop(neg_heap))
            else: print(heapq.heappop(pos_heap))
        elif len(neg_heap):
            print(-heapq.heappop(neg_heap))
        elif len(pos_heap):
            print(heapq.heappop(pos_heap))
        else: print(0)