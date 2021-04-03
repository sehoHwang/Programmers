#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 101;
queue<pair<int,int>> q;
bool visit[MAX][MAX];

int maze[MAX][MAX];
int check[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int n, int m){
    int x = 0;
    int y = 0;

    q.push(make_pair(0,0));
    visit[0][0] = true;

    while(!q.empty()){
        x = q.front().second;
        y = q.front().first;
        q.pop();

        for(int i=0; i<4; i++){
            int nextx = x+dx[i];
            int nexty = y+dy[i];
            if(nextx<m && nextx>=0 && nexty<n && nexty>=0 && !visit[nexty][nextx] && maze[nexty][nextx]==1){
                q.push(make_pair(nexty, nextx));
                visit[nexty][nextx] = true;
                check[nexty][nextx] = check[y][x] + 1;
            }
        }

    }
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        for(int j=0; j<m; j++){
            char tmp = str[j];
            maze[i][j] = tmp-'0';
        }
    }

    bfs(n, m);
    cout<<check[n-1][m-1]+1;
    return 0;
}