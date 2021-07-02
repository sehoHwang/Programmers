def pretreat(exp):
    start = 0
    for idx, e in enumerate(exp):
        if e in operator:
            operands.append(exp[start:idx])
            start = idx+1
            operators.append(e)
    operands.append(exp[start:len(exp)])

def find_pos():
    prior = 3
    pos = 0
    for idx, opt in enumerate(operators):
        if operator[opt]<prior:
            prior = operator[opt]
            pos = idx
    return pos

def calculate(position):   
    cur_opt = operators[position]
    result = 0
    if cur_opt =='*':
        result = operands[position]*operands[position+1]
    elif cur_opt =='/':
        result = operands[position]//operands[position+1]
    elif cur_opt =='+':
        result = operands[position]+operands[position+1]
    elif cur_opt =='-':
        result = operands[position]-operands[position+1]

    operands[position] = result
    del operands[position+1]
    del operators[position]

input = input()

operands = []
operators = []

operator = dict()
operator['('] = 0
operator['*'] = 1
operator['/'] = 1
operator['+'] = 2
operator['-'] = 2
pretreat(input)
operands = list(map(int, operands))
#print(operands)
#print(operators)
while len(operands)!=1:
    cur_pos = find_pos()
    calculate(cur_pos)
    print(operands)

print(operands[-1])
