def solution(s):
    answer = ''
    
    sp = list(map(int, s.split()))
    
    answer+=str(min(sp))+" "+str(max(sp))
    return answer