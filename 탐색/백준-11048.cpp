/** 솔루션 **/

/*
    dp 문제
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int n, m;

int main(){
    
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int candy;
            scanf("%d", &candy);
            arr[i][j] = candy;
        }
    }
    dp[1][1] = arr[1][1];

    for(int i=2; i<=n; i++){
        dp[1][i] = dp[1][i] + dp[1][i-1];
        dp[i][1] = dp[i][1] + dp[i-1][1];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i][j], arr[i][j] + dp[i-1][j]);
            dp[i][j] = max(dp[i][j], arr[i][j] + dp[i][j-1]);
            dp[i][j] = max(dp[i][j], arr[i][j] + dp[i-1][j-1]);
        }
    }

    cout<<dp[n][m];
    
    return 0;
}