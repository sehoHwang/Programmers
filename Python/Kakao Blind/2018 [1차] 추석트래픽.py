def check(timeline, start):     # 시작점을 기준으로 + 1000(1s)한 값보다 작을 동안 cnt를 증가 후 반환
    cnt = 0
    limit = start + 1000
    for i in timeline:
        if limit > i[0] and i[1]>=start:
            cnt+=1
    return cnt

def solution(lines):
    answer = 1
    timeline = []
    for i in lines:
        sp_line = i.split()
        duration = float(sp_line[2].replace('s',''))*1000
        time = sp_line[1].split(':')
        end = (int(time[0])*3600 + int(time[1])*60 + float(time[2]))*1000
        start = end - duration + 1     # 처리시간이 시작 시간과 끝 시간을 포함하므로 +1
        timeline.append([start, end])
    
    for t in timeline:
        answer = max(answer, check(timeline, t[0]), check(timeline, t[1]))     # 시작점과 종료점에서 각각 check 함수 실행
    
    return answer