from itertools import combinations
import copy

def calc(y1, x1, y2, x2):
    return abs(y1-y2) + abs(x1-x2)

N, M = map(int, input().split())
city = []
chicken = [] # 치킨집 좌표
result = []
for _ in range(N):
    city.append(list(map(int, input().split())))

for i in range(N):
    for j in range(N):
        if city[i][j] == 2:
            chicken.append([i,j])

rm_chicken = list(combinations(chicken, M))  # 운영을 유지할 치킨집

for rm in rm_chicken:  # 각 유지 케이스
    sum = 0
    for i in range(N):
        for j in range(N):
            if city[i][j] == 1:
                val = 2*N
                for r in rm:
                    val = min(val, calc(i, j, r[0], r[1]))
                sum += val
    result.append(sum)

print(min(result))