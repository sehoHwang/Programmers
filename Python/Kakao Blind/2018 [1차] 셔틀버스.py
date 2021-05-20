from collections import defaultdict

def solution(n, t, m, timetable):
    answer = ''
    trans = []
    dic = defaultdict(list)
    last = 540 + (n-1)*t
    for time in timetable:
        hour = int(time.split(':')[0])*60
        minute = int(time.split(':')[1])
        trans.append(hour+minute)
    trans.sort()
    cur = 540
    while cur<=last:
        dic[cur]
        cur+=t
    
    cur = 540
    idx = 0
    while idx<len(trans) and cur<=last:
        if trans[idx] <= cur:
            if len(dic[cur]) < m:
                dic[cur].append(trans[idx])
                idx+=1
            else:
                cur+=t
        else:
            cur+=t

    for d in dic.values():
        d.sort(reverse=True)    
    if len(dic[last]) <m:     # 마지막 시간대에 들어갈 수 있다면 last를 반환
        answer = last
    else:
        if len(dic[last])==m: # 그렇지 않다면 마지막 다음으로 늦은 시간대의 마지막 구간을 반환
            answer = dic[last][0]-1
    
    return str((answer//60)).zfill(2) + ":" + str((answer%60)).zfill(2) # string zfill() 함수를 통해 0을 추가