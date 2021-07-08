input = input()
answer = []
start = 0
for i in range(1,len(input)):
    if input[i] == input[start]:
        continue
    if i-start == 1:
        answer.append(input[start])
    else:
        answer.append(str(i-start)+input[start])
    start = i
if len(input)-start == 1:
    answer.append(input[start])
else:
    answer.append(str(len(input)-start)+input[start])

for ans in answer:
    print(ans, end="")
    