#include <iostream>
#include <cstdio>

using namespace std;

int arr[101][101];
int n;
int m;
bool visit[101];
int total = 0;
void dfs(int y){
    if(!visit[y]){
        cout<<"첫 방문 : "<<y<<endl;
        visit[y] = true;
        total++;
        for(int i=1; i<=n; i++){
            if(arr[y][i] == 1){
                dfs(i);
            }
        }
    }
}

int main(){
    int y, x;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &y, &x);
        arr[y][x] = arr[x][y] = 1;
    }

    dfs(1);
    cout<<total-1;
    return 0;
}