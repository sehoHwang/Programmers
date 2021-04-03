#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX = 1001;

bool visit[MAX];
vector<int> adj[MAX];
queue<int> q;

void dfs(int x){
    visit[x] = true;
    printf("%d ", x);
    for(int y : adj[x]){
        if(!visit[y]){
            dfs(y);
        }
    }
}

void bfs(int x){
    visit[x] = true;
    q.push(x);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        printf("%d ", tmp);
        for(int y : adj[tmp]){
            if(!visit[y]){
                q.push(y);
                visit[y] = true;
            }
        }
        
    }
}

int main(){
    int N, M, V;
    int s, e;
    scanf("%d %d %d", &N, &M, &V);

    for(int i=0; i<M; i++){
        scanf("%d %d", &s, &e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i=1; i<N; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(V);
    printf("\n");
    memset(visit, false, sizeof(visit));
    bfs(V);
    
    return 0;
}