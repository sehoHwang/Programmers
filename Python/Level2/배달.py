"""
    Solution (Deque 사용 solution) -> 효율성 높음

    1. dist를 dictionary로 초기화를 시켜준다. (1일 경우만 0, 나머지는 INF)

    2. dictionary 형태로 nodes를 초기화해준다. (양방향이므로 반대로도 적용)

    3. 다음 노드의 dist 값이 현재 노드 dist 값 + 거리보다 크면 최신화 시킨다. (bfs 사용)

    4. dist를 순회하며 K보다 작거나 같은 갯수를 세준다.
"""
from collections import deque
def solution(N, road, K):
    answer = 0

    dist = {i:float('inf') if i!=1 else 0 for i in range(1, N+1)}
    nodes = {}
    for s, e, d in road:
        nodes[s] = nodes.get(s, []) + [(e,d)]
        nodes[e] = nodes.get(e, []) + [(s,d)]
    
    q = deque([1])
    while q:
        cur_node = q.popleft()
        for nxt_node, dis in nodes[cur_node]:
            if dist[nxt_node] > dist[cur_node] + dis:
                dist[nxt_node] = dist[cur_node] + dis
                q.append(nxt_node)
    print(dist)
    return len([True for i in dist.values() if i<=K])

"""
    Solution (우선순위 큐 사용 solution)
"""

from queue import PriorityQueue
def solution(N, road, K):
    answer = 0

    
    dist = {i : float('inf') for i in range (1,N+1)}
    dist[1] = 0
    
    q = PriorityQueue()
    q.put([1,0])
    
    while not q.empty():
        cur_node, cur_cost = q.get()
        for src, dest, dis in road:
            nxt_cost = dis + cur_cost
            if cur_node == src and nxt_cost < dist[dest]:
                dist[dest] = nxt_cost
                q.put([dest, nxt_cost])
            if cur_node == dest and nxt_cost < dist[src]:
                dist[src] = nxt_cost
                q.put([src, nxt_cost])
    return len([True for i in dist.values() if i<=K])
    
