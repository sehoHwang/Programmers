def isAble(n, times):
    tmp = 0
    for t in times:
        tmp += n//t
    return tmp

def solution(n, times):
    
    s, e = 1,  1000000000*n
    answer = e
    while s<=e:
        mid = (s+e)//2
        if isAble(mid, times)>=n: 
            answer = min(answer, mid) # 6을 만족하는 값들 중 최소인 값을 반환해야 하므로 
            e = mid-1                 # 6 이상일 때마다 answer와 mid 값 중 최솟값을 answer에 저장해준다.
        else:
            s = mid+1
    
    return answer