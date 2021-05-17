
# bfs 풀이

from collections import deque

def solution(n, computers):
    answer = 0
    visit = [False for i in range(n)]
    q = deque()
    
    for b in range(n):
        if visit[b] == False:
            q.append(b)
            while q:
                cur = q.popleft()
                visit[cur] = True
                for i in range(len(computers[cur])):
                    if visit[i]==False and computers[cur][i] == 1:
                        q.append(i)
            answer+=1
    
    return answer


# dfs 풀이

from collections import deque

def dfs(s, visit, computers):
    visit[s] = True
    for i in range(len(computers[s])):
        if visit[i]==False and computers[s][i] == 1:
            dfs(i, visit, computers)

def solution(n, computers):
    answer = 0
    visit = [False for i in range(n)]
    
    for i in range(n):
        if visit[i] == False:
            dfs(i, visit, computers)
            answer+=1
    return answer