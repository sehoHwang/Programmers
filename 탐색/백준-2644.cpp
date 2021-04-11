/** 솔루션 **/

/*
    1. visit을 활용한 dfs
*/


#include <iostream>

using namespace std;

int arr[101][101];
bool visit[101];
int n, m, s, e;
int result = 0;

void dfs(int y, int total){
    visit[y] = true;
    for(int i=1; i<=n; i++){
        if(arr[y][i] == 1 && !visit[i]){
            
            if(i==e){
                result = total+1;
                return;
            }
            dfs(i, total+1);
        }
    }
}

int main(){
    int y, x;
    scanf("%d", &n);
    scanf("%d %d", &s, &e);
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%d %d", &y, &x);
        arr[y][x] = arr[x][y] = 1;
    }
    
    dfs(s, 0);

    if(result == 0)
        cout<<"-1";
    else
        cout<<result;
    
    return 0;
}