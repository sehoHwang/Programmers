/** 문제설명 **/

/*
    n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3
*/

/** 솔루션 **/

/*
    dfs를 사용해서 문제를 풀었다.

    값을 더하거나 빼 나갈때 마다 numbers 벡터를 매개변수로 계속 가져갔는데, 
    
    이를 값 복사 형식이 아닌 레퍼런스 형식으로 참조를 시켰더니 시간이 비약적으로 감소하였다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(vector<int> &numbers, int comp, int target, int sum, int n){
    if(n == comp){
        if(sum == target){
            answer++;
        }
        return;
    }
    
    dfs(numbers, comp, target, sum+numbers[n], n+1);
    dfs(numbers, comp, target, sum-numbers[n], n+1);
    
}

int solution(vector<int> numbers, int target) {
    int sum = 0;
    int len = numbers.size();
    string tmp = "";
    dfs(numbers, len, target, sum, 0);

    
    return answer;
}