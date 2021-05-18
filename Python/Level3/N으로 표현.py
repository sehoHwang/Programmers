def solution(N, number):
    answer = 0
    if number == N:   # number가 N과 같으면 1을 반환
        return 1
    s = [set() for i in range(8)]  # N의 사용 횟수에 따른 집합 set을 list에 담는다.
    for i, x in enumerate(s):
        x.add(int(str(N)*(i+1)))  # enumerate로 index, set()을 가져와 N, NN, NNN, ..., NNNNNNNN로 초기화
    
    for i in range(1, 8):
        for j in range(i):
            for x in s[j]:
                for y in s[i-j-1]:
                    s[i].add(x+y)
                    s[i].add(x*y)
                    s[i].add(x-y)
                    if y!=0:
                        s[i].add(x//y)
        if number in s[i]:   # 최솟값 반환이기에 number가 set에 속하면 i+1을 반환
            return i+1
    return -1   # 8개를 사용할 때까지 number가 나오지 않으면 -1 반환