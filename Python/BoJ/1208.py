from itertools import combinations

n, s = map(int, input().split())

numbers = list(map(int, input().split()))
left, right = numbers[:n//2], numbers[n//2:]

l_sum, r_sum = [], [] # 왼쪽, 오른쪽의 부분수열의 합
ans = 0

for i in range(n//2+1):
    cm = list(combinations(left, i))
    for c in cm:
        l_sum.append(sum(c))

for i in range(n-n//2+1):
    cm = list(combinations(right, i))
    for c in cm:
        r_sum.append(sum(c))

l_sum.sort()
r_sum.sort(reverse=True)

len_l, len_r = len(l_sum), len(r_sum)
l_p, r_p = 0, 0

while l_p<len_l and r_p<len_r:
    cur_sum = l_sum[l_p] + r_sum[r_p]
    if cur_sum == s:
        l_p+=1
        r_p+=1
        c1 , c2 = 1, 1
        while l_p < len_l and l_sum[l_p] == l_sum[l_p-1]:
            c1+=1
            l_p+=1

        while r_p < len_r and r_sum[r_p] == r_sum[r_p-1]:
            c2+=1
            r_p+=1

        ans += c1*c2 # 순서쌍 갯수 반영

    elif cur_sum < s:
        l_p+=1

    elif cur_sum > s:
        r_p+=1

if s == 0: # 공집합을 제외시켜야하는데, s가 0이면 공집합일 경우가 포함이 되므로
    ans-=1

print(ans)