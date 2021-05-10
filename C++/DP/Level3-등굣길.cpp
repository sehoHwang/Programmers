/** 솔루션 **/

/*
    1. dfs와 dp를 같이 사용해 해결하였다.

    2. 다음에는 순수 dp로만 해결해보아야겠다.
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int destY, destX;
int answer;
int arr[101][101];
int dp[101][101];
int visit[101][101];

int dfs(int y, int x){
    if(y==destY && x == destX){
        return 1;
    }
    if(y>destY || x>destX)
        return 0;
    
    if(!visit[y][x]){
        visit[y][x] = true;
        if(arr[y+1][x]!=-1){
            dp[y][x] += dfs(y+1, x);
        }
        if(arr[y][x+1]!=-1){
            dp[y][x] += dfs(y, x+1);
        }
    }
    
    return dp[y][x]%1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {

    destY = n;
    destX = m;
    for(int i=0; i<puddles.size(); i++){
        int y = puddles[i][1];
        int x = puddles[i][0];
        arr[y][x] = -1;
    }
    
    answer = dfs(1,1);
    
    return answer;
}