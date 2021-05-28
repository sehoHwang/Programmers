# bfs

from collections import deque

def trans(a, b):
    cnt=0
    for s1, s2 in zip(a,b):
        if s1!=s2:
            cnt+=1
    if cnt==1:
        return True
    return False

def solution(begin, target, words):
    visit = [0 for _ in range(len(words))]
    answer = 0
    if target not in words:
        return 0
    
    q = deque()
    for idx, w in enumerate(words):
        if trans(begin, w):
            q.append([w, 1])
            visit[idx] = 1
    while q:
        top = q.popleft()
        if top[0] == target:
            return top[1]
        for idx, w in enumerate(words):
            if visit[idx] == 0 and trans(top[0], w):
                q.append([w, top[1]+1])
    
    return answer
