# dfs 풀이

from itertools import permutations

gtarget = 0
answer = 0

def dfs(numbers, num, total):
    if num == len(numbers):
        if total == gtarget:
            global answer
            answer += 1
        return
    
    dfs(numbers, num+1, total-numbers[num])
    dfs(numbers, num+1, total+numbers[num])
    
    

def solution(numbers, target):
    global gtarget
    gtarget = target
    dfs(numbers, 0, 0)
    return answer

# 완전 탐색 
# product solution

from itertools import permutations, product

def solution(numbers, target):
    answer = 0
    l = [(-x, x) for x in numbers]
    s = list(map(sum, product(*l)))
    return s.count(target)

# bfs 풀이

import collections

def solution(numbers, target):
    answer = 0
    
    queue = collections.deque([(0,0)])
    while queue:
        cur_total, cur_num = queue.popleft()
        if cur_num == len(numbers):
            if cur_total == target:
                answer+=1
        else:
            queue.append((cur_total-numbers[cur_num], cur_num+1))
            queue.append((cur_total+numbers[cur_num], cur_num+1))
    
    return answer