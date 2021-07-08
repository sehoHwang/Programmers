def string_to_list(word):
    temp = []
    for w in word:
        temp.append(w)
    return temp

def camel_to_snake(word):
    info = []
    for idx,w in enumerate(word):
        if 'A'<=w<='Z':
            info.append((idx,w))
    
    for i in info:
        idx, alpha = i[0], i[1]
        word[idx] = '_'+ alpha.lower()


def snake_to_camel(word):
    info = []
    for idx,w in enumerate(word):
        if '_' in w :
            info.append(idx+1)
    
    for i in info:
        idx = i
        word[idx] = word[idx].upper()
    
    j = 0
    while '_' in word:
        if word[j] == '_':
            del word[j]
            j-=1
        j+=1    

input = input()

words = string_to_list(input)

if '_' in words:
    snake_to_camel(words)
else:
    camel_to_snake(words)

for w in words:
    print(w,end="")
print()