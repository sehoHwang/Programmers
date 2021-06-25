t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print('YES')
        continue
    phone = []
    flag = 0
    for _ in range(n):
        phone.append(input())
    
    phone.sort()
    for i in range(len(phone)-1):
        
        if  phone[i] == phone[i+1][0:len(phone[i])]:
            flag = 1
            print('NO')
            break
    if flag == 0:
        print('YES')