#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAX = 200000; // 2e5

vector<int> edge[MAX];
set<int> s;
int key[MAX], needKey[MAX];
bool check_visit[MAX];

void BFS(int node){
    queue<int> q;
    q.push(node);
    check_visit[node] = true; // -> 이 부분이 어렵다
    
    if(needKey[0] != 0) return; // 0보다 먼저 가야할 방이 있다면 false
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        needKey[key[tmp]] = 0;
        
        if(s.find(key[tmp]) != s.end()){ // s에 key[tmp] (tmp 다음에 이동해야할 방)이 set에 저장되어 있다면 이제 빼서 큐에 넣어주기
            s.erase(key[tmp]); // set에서 지워주고
            q.push(key[tmp]); //  queue에 넣어줘서 다음에 이동할 수 있도록 해준다.
            check_visit[key[tmp]] = 1;
        }
        for(int it : edge[tmp]){ // tmp 방과 연결된 방들을 확인해준다.
            if(check_visit[it]) continue; // 이미 방문했다면 그냥 pass
            if(needKey[it] != 0){ // it번 방보다 먼저 나와야 하는 방이 존재한다면
                s.insert(it); // set에 삽입해주기
                continue;
                // 방문은 하지 않는다 -> it번 방보다 먼저 나와야 하는 방이 있으니까 set에 넣어주고
                // set에서 queue로 이동하기를 기다린다.
            }
            check_visit[it] = true;
            q.push(it);
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(auto &it : path){
        edge[it[0]].push_back(it[1]);
        edge[it[1]].push_back(it[0]);
    }
    // order[][0] -> order[][1];
    for(auto & it : order){
        key[it[0]] = it[1]; // key[먼저] = 나중
        needKey[it[1]] = it[0]; // needKey[나중] = 먼저
    }
    BFS(0);
    for(int i = 0 ; i < n ; i++) if(!check_visit[i]) return false;
    return true;
}

/*
    dfs 풀이
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
bool vis[MAXN];
int prior[MAXN],hang[MAXN];
vector<int> edge[MAXN];

void visit(int v){
    if(vis[v])return;
    
    if(!vis[prior[v]]){		// 2
        hang[prior[v]]=v;
        return;
    }
 
    vis[v]=true;
    visit(hang[v]);		// 3
    for(int u:edge[v])visit(u);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    // 1
    for(auto &a:path){
        edge[a[0]].push_back(a[1]);
        edge[a[1]].push_back(a[0]);
    }
    for(auto &a:order)prior[a[1]]=a[0];

    if(prior[0])return false;

    vis[0]=true;
    for(int u:edge[0])visit(u);
    
    for(int i=0;i<n;++i)if(!vis[i])return false;
    return true;
}