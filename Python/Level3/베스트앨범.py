from collections import defaultdict 

def solution(genres, plays):
    answer = []
    music = defaultdict(list)
    total = defaultdict(int)
        
    for i in range(len(genres)):
        total[genres[i]] += plays[i]
        music[genres[i]].append((plays[i], i))
    
    for m, mv in zip(music, music.values()):
        music[m] = sorted(mv, reverse=True, key = lambda x:(x[0], -x[1]))
    
    total = sorted(total.items(), reverse=True, key=lambda x:x[1])
    
    for t in total:
        cur = t[0]
        cur_len = len(music[cur])
        if cur_len >= 2:
            answer.append(music[cur][0][1])
            answer.append(music[cur][1][1])
        elif cur_len == 1:
            answer.append(music[cur][0][1])
        else:
            continue
    return answer