#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

int dp[101][10]; // [단계][끝자리 수]


int main(){
    int n;
    int result = 0;
    scanf("%d", &n);
    dp[1][0]=0;
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j=1; j<9; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }

    for(int i=0; i<=9; i++){
        result = (result + dp[n][i])%1000000000;
    }

    cout<<result;

    return 0;
}