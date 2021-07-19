import heapq

def Find(x):
    if p[x] == x:
        return x
    else:
        y = Find(p[x])
        p[x] = y
        return p[x]

def Union(x, y):
    x = p[x]
    y = p[y]
    if x!=y:
        p[y] = Find(x)

n, m = map(int, input().split())

p = [i for i in range(n+1)]
ans = 0
G = []

for _ in range(m):
    a, b, c = map(int, input().split())
    G.append([c,a,b]) # 가중치, 시작 노드, 도착 노드

G.sort(key = lambda x:x[0])
edge_cnt = 0
for w, u, v in G:
    if Find(u)!=Find(v):
        Union(u, v)
        ans+=w
        edge_cnt+=1

    if edge_cnt == n-2:
        break

print(ans)