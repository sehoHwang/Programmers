/** 솔루션 **/

/*
    1. dp를 이용한 경로 찾기 문제이다.

    2. 경로를 겹치지 않게하기 위해 visit을 사용

    3. 각 dfs는 매개변수 x가 주어진 길이에 해당할 경우 1을 return하며 이 외에는 dp[x]를 return한다.

    4. 매 dfs마다 dp[x] += dfs(x+1)
                dp[x] += dfs(x+2) 를 진행한다.
*/


#include <string>
#include <vector>

using namespace std;

bool visit[2001];
long long dp[2001];
int finish;

long long dfs(int x){
    if(x==finish)
        return 1;
    if(x > finish)
        return 0;
    if(!visit[x]){
        visit[x] = true;
        dp[x] += dfs(x+1);
        dp[x] += dfs(x+2);
    }
    return dp[x]%1234567;
}

long long solution(int n) {
    long long answer = 0;
    finish = n;
    dfs(0);
    answer = dfs(0);
    return answer;
}