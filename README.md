# Python Std Library

* 내장 함수 : 기본 입출력 함수부터 정렬 함수까지 기본적인 함수들을 제공
	* 파이썬 프로그램을 작성할 때 없어서는 안되는 필수적인 기능을 포함

* itertools : 파이썬에서 반복되는 형태의 데이터를 처리하기 위한 유용한 기능들을 제공
	* 특히 순열과 조합 라이브러리는 코딩 테스트에서 자주 사용됨

* heaps : 힙 자료구조를 사용
	* 일반적으로 우선순위 큐 기능을 구현하기 위해 사용

* bisect : 이진 탐색 기능을 제공

* collections : 덱(duque), 카운터(counter) 등의 유용한 자료구조를 포함

* math : 필수적인 수학적 기능을 제공
	* 팩토리얼, 제곱근, 최대공약수(GCD), 삼각함수 관련 함수부터 파이(pi)와 같은 상수를 포함


### 순열과 조합
- - - -
* 순열

```python
from itertools import permutations

data = ['A', 'B', 'C']

result = list(permutations(data, 3))
print(result)
```

* 조합
```python
from itertools import combinations

data = ['A', 'B', 'C']

result = list(combinations(data, 2)) # 2개를 뽑는 모든 조합 구하기
print(result)
```

* 중복 순열과 중복 조합
```python
# 중복 순열
from itertools import product
data = ['A', 'B', 'C']

result = list(product(data, repeat=2)) # 2개를 뽑는 모든 순열 구하기 (중복 허용)

# 중복 조합
from itertools import combinations_with_replacement

data = ['A', 'B', 'C']

result = list(combinations_with_replacement(data, 2)) # 2개를 뽑는 모든 조합 구하기 (중복 허용)

```

### Counter
- - - -
* 파이썬 collections 라이브러리의 Counter는 등장 횟수를 세는 기능을 제공
* 리스트와 같은 반복 가능한 객체가 주어졌을 때 내부의 원소가 몇 번씩 등장했는지를 알려줌

```python
from collections import Counter

counter = Counter(['red', 'blue', 'red', 'green', 'blue', 'blue])

print(counter['blue']) # 'blue'가 등장한 횟수 출력
print(counter['red']) # 'green'이 등장한 횟수 출력
print(dict(counter) # 사전 자료형으로 반환
```


### 최대 공약수와 최소 공배수
- - - -
```python
import math

def lcm(a,b):
	return a*b // math.gcd(a,b)

a = 21
b = 14

print(math.gcd(21, 14)) # 최대 공약수(GCD) 계산
print(lcm(21, 14)) # 최소 공배수(LCM) 계산
```

