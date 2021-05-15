import heapq
def solution(prices):
    answer = [0] * len(prices)
    heap = []
    for i in range(len(prices)):
        if len(heap) == 0 :
            heapq.heappush(heap, (-prices[i], i))
        else:
            maxVal = -heap[0][0]
            while len(heap)>0 and maxVal > prices[i]:
                val, idx = heapq.heappop(heap)
                answer[idx] = i-idx
                if len(heap) > 0:
                    maxVal = -heap[0][0]
            
            heapq.heappush(heap, (-prices[i], i))
    
    while len(heap) > 0:
        val, idx = heapq.heappop(heap)
        answer[idx] = len(prices)-1-idx
    return answer