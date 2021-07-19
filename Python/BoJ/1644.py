import math

def get_sum(start, end):
    sum = 0
    for i in range(start ,end+1):
        sum += prime_num[i]
    return sum

def isPrime(num):
    if num == 1:
        return False
    if num == 2:
        return True

    for i in range(2, int(math.sqrt(num))+1):
        if num%i == 0:
            return False
    return True

ans = 0
n = int(input())
prime_num = []
for i in range(1,n+1):
    if isPrime(i):
        prime_num.append(i)
#print(prime_num)
length = len(prime_num)
l_p, r_p = 0, 0
flag = 0
while l_p<=length-1 or r_p<=length-1:
    if l_p==length-1 and r_p==length-1:
        flag = 1
    if l_p==length:
        l_p = length-1
    if r_p==length:
        r_p = length-1

    cur_val = get_sum(l_p, r_p)

    if cur_val == n:
        ans += 1
        l_p+=1
        r_p+=1
    
    elif cur_val < n:
        r_p+=1

    elif cur_val > n:
        l_p+=1
        
    if flag == 1:
        break

print(ans)