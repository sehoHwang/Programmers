/** 솔루션 **/

/*
    1. bfs 문제이다.
*/


#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool arr[20001][20001];
bool visit[20001];
int result[20001];

void bfs(int *len){
    int cur = 1;
    queue<int> q;
    
    q.push(1);
    visit[1] = true;
    
    while(!q.empty()){
        int top = q.front();
        
        q.pop();
        
        for(int i=2; i<=*len; i++){
            if(arr[top][i] && !visit[i]){
                q.push(i);
                result[i] = result[top]+1;
                visit[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for(int i=0; i<edge.size(); i++){
        int y = edge[i][0];
        int x = edge[i][1];
        arr[y][x] = arr[x][y] = true;
    }
    
    int maxnum = 0;
    
    bfs(&n);
    
    for(int i=2; i<=n; i++){
        //cout<<result[i]<<endl;
        if(maxnum < result[i])
            maxnum = result[i];
    }
    
    for(int i=2; i<=n; i++){
        if(result[i] == maxnum)
            answer++;
    }

    return answer;
}