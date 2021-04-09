#include <iostream>
#include <cstdio>

using namespace std;

int arr[101][101];
int visit[101];
int n;

int result = 0;

void dfs(int x){
    visit[x] = 1;
    result++;
    for(int i=1; i<=n; i++){
        if(arr[x][i] == 1 && visit[i]==0){
            dfs(i);
        }
    }
    return;
}

int main(){
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        arr[r][c] = arr[c][r] = 1;
    }
    
    dfs(1);
    cout<<result-1;
    return 0;
}