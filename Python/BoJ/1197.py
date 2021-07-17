def Find(x):
    if p[x] == x: # 본인 부모일 경우 x 반환
        return x
    else:
        y = Find(p[x]) # x의 조상을 찾아서 y에 대입
        p[x] = y # p의 조상을 y로 갱신
        return p[x] # p[x] 반환

def Union(x, y):
    x = p[x]
    y = p[y]
    if x!=y:
        p[y] = Find(x)

v,e = map(int ,input().split())
total_v = 0
cnt = 0
G = []
p = [i for i in range(v+1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    G.append([c, a, b]) # 가중치, 출발, 도착

G.sort(key=lambda x:x[0]) # 가중치를 기준으로 정렬
#print('그래프 상태 : ', G)
for w, start, end in G:
    if Find(end) != Find(start):
        Union(start,end)
        cnt+=1
        total_v+=w
    if cnt == v-1:
        break    
#print(visited_nodes)
print(total_v)