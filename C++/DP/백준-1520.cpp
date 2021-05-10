/** 솔루션 **/

/*
    1. dfs와 dp를 동시에 사용해야 한다.

    2. dp[y][x] = -1 즉, 첫 방문일 경우에만 계속해서 dfs를 한다.

    3. dp[y][x]는 dfs의 반환값을 더해준다.
*/


#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];
int m,n;

int dfs(int y, int x){
    if(y==m && x==n){
        return 1;
    }
    else if(dp[y][x] == -1){
        dp[y][x] = 0;
        if(y+1<=m && x<=n && arr[y+1][x] < arr[y][x]){
            dp[y][x] += dfs(y+1, x);
        }
        if(y-1>=1 && x<=n && arr[y-1][x] < arr[y][x]){
            dp[y][x] += dfs(y-1, x);
        }
        if(y<=m && x+1<=n && arr[y][x+1] < arr[y][x]){
            dp[y][x] += dfs(y, x+1);
        }
        if(y<=m && x-1>=1 && arr[y][x-1] < arr[y][x]){
            dp[y][x] += dfs(y, x-1);
        }

        
    }
    return dp[y][x];
}

int main(){
    int input;
    scanf("%d %d", &m, &n);

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &input);
            arr[i][j] = input;
            dp[i][j] = -1;
        }
    }

    cout<<dfs(1,1);

    return 0;
}