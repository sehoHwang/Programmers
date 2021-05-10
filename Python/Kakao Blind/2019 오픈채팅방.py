def solution(record):
    answer = []
    userid = []
    sentence = []
    dict = {}
    for x in record:
        arr = x.split(' ')
        instruction = arr[0]
        id = arr[1]
        if len(arr) == 3:
            nick = arr[2]
        
        if instruction == "Enter":
            userid.append(id)
            sentence.append("님이 들어왔습니다.")
            dict[id] = nick
            
        elif instruction == "Leave":
            userid.append(id)
            sentence.append("님이 나갔습니다.")
        else:
            dict[id] = nick
    
    for x in range(0, len(sentence)):
        answer.append(dict[userid[x]]+sentence[x])
    
    return answer