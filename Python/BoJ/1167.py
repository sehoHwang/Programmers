from collections import defaultdict, deque
result = []

def bfs(start):
    max_dis = 0
    max_node = 0
    visit = [False for _ in range(V+1)]
    visit[start] = True
    q = deque()
    for n in graph[start]:
        dest, dis = n[0], n[1]
        
        q.append((dest,dis))
        visit[dest] = True
    while q:
        cur, cur_dis = q.popleft()
        
        if max_dis < cur_dis:
            max_dis = cur_dis
            max_node = cur

        for n in graph[cur]:
            dest, dis = n[0], n[1]
            
            if visit[dest] == False:
                q.append((dest,cur_dis+dis))
                visit[dest] = True
    return max_dis, max_node

V = int(input())

nodes = defaultdict(list)
graph = defaultdict(list)

for _ in range(V):
    c = list(map(int, input().split()))
    for e in range(1, len(c) - 2, 2):
        graph[c[0]].append((c[e], c[e+1]))

dis, node = bfs(1)

dis, node = bfs(node)
print(dis)