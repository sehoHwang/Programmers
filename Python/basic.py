# -*- coding: utf-8 -*-
# 파이썬 실수

"""
a = 1000
print(a)

b = 0.3+0.6
print(b)
if round(b,2) == 0.9:
    print(True)
else:
    print(False)
"""

# 나눗셈

"""
a = 1000
b = 11
c = a/b
print('a/b = ', a)
"""

# 리스트

"""
a = [1,2,3,4,5,6,7]

print(a[-1]) # 뒤에서 첫 번째 원소 출력

print(a[1:4]) # 리스트 슬라이스
"""

# 리스트 컴프리헨션

"""
b = [i for i in range(5,10)]
print(b) 

odd = [i for i in range(20) if i%2==1]
print(odd)
"""


# 리스트 관련 기타 메서드

"""
    append() : 리스트에 삽입 (list.append())

    sort() : 오름차순으로 정렬 (list.sort())
             내림차순으로 정렬 (list.sort(reverse = True))
    
    reverse() : 리스트의 원소의 순서를 모두 뒤집어 놓는다. (list.reverse)

    insert() : 특정한 인덱스 위치에 원소를 삽입할 때 사용 (list.insert(idx, value))

    count() : 리스트에서 특정한 값을 가지는 데이터의 개수를 센다. (list.count(value))

    remove() : 특정한 값을 갖는 원소를 제거하는데, 값을 가진 원소가 여러 개면 하나만 제거한다 (list.remove())

"""

# 리스트에서 특정 값을 가지는 원소를 모두 제거하기

"""
a = [1,2,3,4,5,5]
remove_set = {3,5}

result = [i for i in a if i not in remove_set]
print(result)
"""

# 문자열

"""
a = "string"
print(a*3)
print(a[1:4])  # 문자열은 인덱스로 수정이 불가능하다.
"""

# 튜플

"""

- 튜플은 리스트와 비슷하지만 ()를 사용한다.
- 수정이 불가능하다.
- 공간 효율적이다.

* 튜플을 사용하면 좋은 경우

1. 서로 다른 성질의 데이터를 묶어서 관리해야 할 때
2. 데이터의 나열을 해싱의 키 값으로 사용해야 할 때
3. 리스트보다 메모리를 효율적으로 사용해야 할 때

"""

# 사전 자료형

"""

- c++에서의 map과 비슷
- 키와 값의 쌍을 데이터로 가지는 자료형
- 변경 불가능한 자료형을 키로 사용할 수 있음
- 데이터의 조회 및 수정에 있어서 O(1)의 시간에 처리할 수 있음

"""

"""
data = dict()
data['사과'] = 'Apple'
data['바나나'] = 'Banana'
data['코코넛'] = 'Coconut'

print(data['사과'])

key_list = data.keys()
val_list = data.values()

print(key_list)
print(val_list)
"""

# 집합 자료형

"""
data = set([1,1,2,3,4,4,5]) # 초기화 방법 1
print(data)

data = {1,1,2,3,4,4,5} # 초기화 방법 2
print(data)

data.add(10) # 새로운 원소 한개 추가
data.update([10, 11]) # 새로운 원소 여러개 추가
print(data)

data.remove(3) # 특정 값 제거
print(data)
"""
import sys
# 입력

"""
a = list(map(int, input().split()))
print(a)

# 빠른 입력을 위한 sys 라이브러리 사용
data = sys.stdin.readline().rstrip()
print(data)
"""

# 출력

"""
a = 1
b = 2
print(a,b)
print(7)

print(f"정답은 {a}입니다.")
"""

# if 문에서 pass
"""
a= 30

if a >= 50:
    print("a>=50")
elif a== 30:
    pass
else:
    print("nothing")
"""

# for 문

"""
array = [9,8,7,6,5]
array.sort()
for x in array:
    print(x)
"""

# global variable

"""
a = 10

def func():
    global a
    a+=1
    print(a)

func()
"""

# 람다 표현식


#a = [('홍길동', 50), ('이순신', 32), ('아무개', 74)]
#print(sorted(a, key = lambda x:x[1]))

list1 = [1,2,3,4,5]
list2 = [6,7,8,9,10]

result = map(lambda a,b : a+b, list1, list2)
print(list(result))