# 주의! -> root가 0이 아닐 수도 있음
# -1이 처음으로 나타나는 인덱스를 기준으로 bfs시 성공
from collections import defaultdict, deque

N = int(input())
visit = [0 for _ in range(N)] # 리프노드 방문 확인 리스트

ans = 0 # 리프노드 갯수
tree = defaultdict(list) # tree를 dictionary로 저장
q = deque()
for i in range(N):
    tree[i]

tmp = list(map(int,input().split()))

D = int(input())
root = 0
for i, t in enumerate(tmp) : 
    if t != -1:
        tree[t].append(i)
    else:
        root = i

del(tree[D]) # D에 대한 서브트리 삭제

for v in tree.values():
    if D in v:
        v.remove(D) # D로 진입하는 경우 삭제

for v in tree[root]:
    q.append(v)

while q:
    top = q.popleft()
    if len(tree[top]) == 0: # 리프노드일 경우
        if visit[top] == 0: # 방문을 안한 리프노드일 경우
            ans+=1
            visit[top] = 1
            continue
        else: # 방문을 한 리프노드일 경우 생략
            continue
   
    else: # 리프노드가 아닐 경우
        for n in tree[top]:
            if visit[n] == 0:
                q.append(n)
if ans == 0 and D != root:
    ans = 1
print(ans)