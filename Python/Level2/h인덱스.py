def solution(citations):
    answer = 0
    
    maxVal = max(citations)
    citations.sort()
    idx = 0
    for i in range(maxVal+1):
        while citations[idx]<i:
            idx+=1
        if i<= len(citations)-idx:
            answer = max(answer, i)

    return answer