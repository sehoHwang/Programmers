/** 솔루션 **/

/*
    1. 백준 10844번과 같은 솔루션이다.

    2. dp[단계 수][끝자리 숫자]로 계산하면 간단히 해결된다.
*/


#include <iostream>

using namespace std;
int n;
long long dp[91][2];
int main(){
    scanf("%d", &n);
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][0];

        dp[i][1] = dp[i-1][0];
    }

    long long result = dp[n][0] + dp[n][1];
    cout<<result;

    return 0;

}