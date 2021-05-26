import math

def solution(n, words):
    answer = [0,0]

    once = set() # 이미 나온 단어 집합
    before = ""
    for idx, w in enumerate(words):
        person = (idx+1)%n
        if person == 0:
            person = n
        num = ((idx//n))+1
        if w in once or (len(before)!=0 and before[len(before)-1] != w[0]):
            answer = [person, num]
            return answer
        once.add(w)
        before = w
    return answer