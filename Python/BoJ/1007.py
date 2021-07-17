from itertools import combinations

T = int(input())
ans = 1000000000
for _ in range(T):
    n = int(input())
    dots = []
    total_x, total_y = 0, 0
    for _ in range(n):
        x, y = map(int, input().split())
        dots.append((x,y))
        total_x+=x
        total_y+=y
    #print('dots : ', dots)

    p = list(combinations(dots,n//2))
    #print('점 2개의 집합 : ', p)
    p_len = len(p)//2
    #print(p_len)
    
    for element in p[:p_len]:
        #print(list(element))
        
        x1_total = 0
        y1_total = 0
        for x1, y1 in element:
            x1_total += x1
            y1_total += y1

        x2_total = total_x - x1_total
        y2_total = total_y - y1_total
        ans = min(ans, ((x1_total-x2_total)**2+(y1_total-y2_total)**2)**0.5)
    print("{:.12f}".format(ans))
    
    