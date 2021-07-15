import heapq

def solution(n, start, end, roads, traps):
    answer = 0
    INF = float('inf')
    dp = [[INF for _ in range(n+1)] for _ in range(1<<len(traps))]
    print(dp)
    """
    traps_index ={value:ind  for ind,value in enumerate(traps) }
    node_list = []
    graph =[[] for _ in range(n+1)]

    for road in roads:
        x,y,pay = road
        graph[x].append([y,pay,0])
        graph[y].append([x,pay,1])

    heapq.heappush(node_list,(0,start,0))
    dp[0][start] = 0
    while node_list:
        cur_time,cur_node,state = heapq.heappop(node_list)
        if end == cur_node:
            answer = cur_time
            break
        if dp[state][cur_node] < cur_time:
            continue
        for next_node,pay,flag in graph[cur_node]:
            next_state = state
            if cur_node in traps:
                if next_node in traps:
                    cur_flag = ((1&(state>>traps_index[cur_node])) + 
                    (1&(state>>traps_index[next_node])))%2
                    next_state = state^(1<<traps_index[next_node])
                else:
                    cur_flag = (1&(state>>traps_index[cur_node]))
            else:
                if next_node in traps:
                    cur_flag =  (1&(state>>traps_index[next_node]))
                    next_state = state^(1<<traps_index[next_node])
                else:
                    cur_flag = 0
            
            if cur_flag == flag:
                if dp[next_state][next_node] > cur_time + pay:
                    dp[next_state][next_node] = cur_time + pay
                    if next_node in traps:
                        heapq.heappush(node_list,(dp[next_state][next_node], next_node,next_state ))
                    else:
                        heapq.heappush(node_list,(dp[next_state][next_node],next_node,next_state))

    return answer
    """
if __name__=='__main__':
    print(solution(3,1,3,[[1, 2, 2], [3, 2, 3]],[2]))