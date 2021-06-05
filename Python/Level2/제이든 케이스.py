def solution(s):
    answer = ''
    voc = []
    space = []
    tmp = ''
    tmp2 = ''
    for s1 in s :
        if s1 == ' ':
            tmp+=' '
            if len(tmp2)!=0:
                voc.append(tmp2)
                tmp2=''
        else:
            if len(tmp)!=0:
                space.append(tmp)
            
            tmp=''
            tmp2+=s1
            
    if len(tmp2)!=0:
        voc.append(tmp2)
    
        
    space.append(' ')
    
    for v, sp in zip(voc, space):
        answer+=v.lower().capitalize()+sp
    if s[-1] == ' ':
        return answer
    else:
        return answer[:-1]