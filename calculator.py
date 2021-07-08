import re
import sys

def tokenize(expStr):
    pat = re.compile(r'(?:(?<=[^\d\.])(?=\d)|(?=[^\d\.]))', re.MULTILINE)
    return [x for x in re.sub(pat, ' ', expStr).split(' ') if x]

def parse_expr(expStr):
    tokens = tokenize(expStr)
    op = dict(zip('*/+-()', (50, 50, 40, 40, 0, 0)))
    output = []
    stack = []

    for item in tokens:
        if item not in op:
            output.append(item)
        elif item == '(':
                stack.append(item)
        elif item == ')':
            while stack != [] and \
                        stack[–1] != '(':
                output.append(stack.pop())
            stack.pop()
        else:
            while stack != [] and \
                    op[stack[–1]] >= op[item]:
                output.append(stack.pop())
            stack.append(item)

    while stack:
        output.append(stack.pop())
    print(output)
    return output

def calc_expr(tokens):
    operations = {
            '*': lambda x, y: y * x,
            '/': lambda x, y: y / x,
            '+': lambda x, y: y + x,
            '-': lambda x, y: y – x
            }

    stack = []

    for item in tokens:
        if item not in operations:
            if '.' in item:
                stack.append(float(item))
            else:
                stack.append(int(item))
        else:
            x = stack.pop()
            y = stack.pop()
            stack.append(operations[item](x, y))
    return stack[–1]


def process(expStr):
    print(calc_expr(parse_expr(expStr)))


if len(sys.argv) > 1:
    x = ' '.join(sys.argv[1:])
else:
    x = input()
process(x)