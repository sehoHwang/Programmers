/** 솔루션 **/

/*
    1. dfs와 dp를 동시에 사용해야 한다.

    2. dp[y][x] = -1 즉, 첫 방문일 경우에만 계속해서 dfs를 한다.

    3. dp[y][x]는 dfs의 반환값을 더해준다.
*/


#include <iostream>
#include <cstdio>

using namespace std;

int arr[101][101];
int dp[101][101];

int n;

long long dfs(int y, int x){
    if(y==n && x==n)
        return 1;

    else if(dp[y][x] == -1){
        dp[y][x] = 0;

        int tmp = arr[y][x];

        if(y+tmp <=n && y+tmp>=1 && x<=n && x>=1){
            dp[y][x] += dfs(y+tmp, x);
        }

        if(x+tmp <=n && x+tmp>=1 && y>=1 && y<= n){
            dp[y][x] += dfs(y, x+tmp);
        }
    }
    return dp[y][x];
}

int main(){
    
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        int num;
        for(int j=1; j<=n; j++){
            scanf("%d", &num);
            arr[i][j] = num;
            dp[i][j] = -1;
        }
    }

    long long result = dfs(1,1);

    printf("%lld\n", result);

    return 0;
}