import heapq

n = int(input())

S = map(int, input().split())
heap = []

for s in S:
    if len(heap) != 0:
        max_ = max(heap)
        if max_>=s:
            heap.remove(max_)
            heap.append(s)
        else:
            heap.append(s)
    else:
        heap.append(s)
        
    print(heap)
