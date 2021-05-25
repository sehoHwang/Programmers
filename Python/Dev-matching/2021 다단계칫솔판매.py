from collections import defaultdict

def solution(enroll, referral, seller, amount):
    answer = []
    node = defaultdict()
    account = defaultdict()
    for e, r in zip(enroll, referral):
        node[e] = r
        account[e] = 0
    account['-'] = 0
    
    for s, a in zip(seller, amount):
        temp = s
        a = 100*a
        while temp in node:
            next = node[temp]
            cur = a - a//10
            nxt = a//10
            if nxt<1:
                account[temp] += cur + nxt
                break
            else:
                account[temp] += cur
                temp = next
                a = nxt
    for ac in account.values():
        answer.append(ac)
    
        
    return answer[:-1]