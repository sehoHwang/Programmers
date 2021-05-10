# 완전 탐색

def solution(progresses, speeds):
    answer = []

    while len(progresses) != 0:
        while progresses[0] < 100:
            for x in range(0, len(speeds)):
                progresses[x] = progresses[x] + speeds[x]
        i=0
        while i<len(progresses) and progresses[i]>=100:
            i+=1
        del progresses[0:i]
        del speeds[0:i]
        answer.append(i)
        
    return answer

# 소요시간을 미리 계산하는 방법 math.ceil() 사용
"""
    1. 소수점 올림 함수인 math.ceil()을 통해 소요시간을 구함

    2. 첫번째 원소보다 큰 값이 나올 때까지 idx 증가

    3. 큰 값이 나타나면 idx - front값을 answer에 추가

    4. 반복문이 끝나면 나머지 값들을 answer에 추가
"""
import math

def solution(progresses, speeds):
    answer = []

    progresses = [math.ceil((100-a)/b) for a,b in zip(progresses, speeds)]
    
    front = 0
    for idx in range(len(progresses)):
        if progresses[idx] > progresses[front]:
            answer.append(idx-front)
            front = idx
    answer.append(len(progresses) - front)
    return answer