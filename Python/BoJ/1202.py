import heapq
        
answer = 0
n, k = map(int, input().split())
bag = []
j = []
for _ in range(n):
    m, v = map(int, input().split())
    heapq.heappush(j,(m, v))

for _ in range(k):
    w = int(input())
    heapq.heappush(bag, w)

capable_gem = [] # 현재 bag의 최대 무게보다 작은 모든 보석들

while bag:
    cur_w = heapq.heappop(bag)
    
    while j and cur_w>=j[0][0]:
        j_w, j_v = heapq.heappop(j)
        heapq.heappush(capable_gem, -j_v)
    
    if capable_gem:
        answer -= heapq.heappop(capable_gem)
    elif not j:
        break

print(answer)
