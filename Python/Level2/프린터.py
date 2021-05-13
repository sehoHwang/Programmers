"""
    Solution

    1. heap을 리스트 형태로 사용

    2. while문을 순회하며 튜플의 첫번째 값을 비교하여 더 큰 값이 있을 경우, pop()후에 push()를 해준다.

    3. pop() 시에 가장 우선순위가 높을 경우 튜플의 두번째 값이 location과 동일할 시, 정답
"""

import heapq

def solution(priorities, location):
    answer = 0
    
    heap = []
    
    for i in range(len(priorities)):
        heap.append((priorities[i], i))
        
    cnt = 1
    
    while len(heap)!=0:
        top = heap[0]
        heap.pop(0)
        if len(heap)!=0 and top[0] < max(heap)[0]:
            heap.append((top[0], top[1]))
        else:
            if top[1] == location:
                answer = cnt
                break
            cnt+=1
    return answer


"""
    Deque를 활용한 풀이

    1. deque는 list보다 월등한 속도를 냄.

    2. enumerate (인덱스, 값)의 형태로 반환.
"""

from collections import deque

def solution(priorities, location):
    answer = 0
    d = deque([(v,i) for i,v in enumerate(priorities)])
    
    while len(d):
        item = d.popleft()
        if d and item[0] < max(d)[0]:
            d.append((item[0], item[1]))
        else:
            answer+=1
            if item[1] == location:
                return answer
    
    return answer