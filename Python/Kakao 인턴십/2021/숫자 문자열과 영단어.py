def isNumber(char):
    if '0'<=char<='9':
        return True
    return False

def solution(s):
    answer = ''
    
    trans = dict()
    trans['zero'] = 0
    trans['one'] = 1
    trans['two'] = 2
    trans['three'] = 3
    trans['four'] = 4
    trans['five'] = 5
    trans['six'] = 6
    trans['seven'] = 7
    trans['eight'] = 8
    trans['nine'] = 9
    
    cur_string = ''
    for idx in range(len(s)):
        
        if isNumber(s[idx])==False:
            cur_string+=s[idx]
            if cur_string in trans:
                answer+=str(trans[cur_string])
                cur_string = ''
        else:
            answer+=s[idx]
    
    return int(answer)