import heapq

def solution(operations):
    answer = []
    q_max = []
    q_min = []
    for o in operations:
        op, num = o.split()
        num = int(num)
        if op == 'I':
            heapq.heappush(q_min, num)
            heapq.heappush(q_max,(num*-1, num))
        else:
            if len(q_max) == 0:
                pass
            elif num == 1:
                max_value = heapq.heappop(q_max)[1]
                q_min.remove(max_value)
            else:
                min_value = heapq.heappop(q_min)
                q_max.remove((min_value*-1,min_value))
    if q_min:
         return [heapq.heappop(q_max)[1], heapq.heappop(q_min)]
    else:
        return [0,0]