#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
int arr[101][101];
bool visit[101][101];
int result = 0;

void dfs(int h){
    //cout<<h<<endl;
    queue<pair<int,int>> q;
    int tmpresult = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int flag = 0;
            //cout<<"for 문 i j "<<i<<" "<<j<<endl;
            if(!visit[i][j] && arr[i][j]>=h){
                visit[i][j] = true;
                q.push(make_pair(i, j));
                //cout<<"시작 정점 : "<<i<<" "<<j<<endl;
                while(!q.empty()){
                    flag = 1;
                    int y = q.front().first;
                    int x = q.front().second;
                    if(arr[y+1][x] >= h && y+1 <=n && !visit[y+1][x]){
                        q.push(make_pair(y+1, x));
                        visit[y+1][x] = true;
                    }
                    if(arr[y][x+1] >= h && x+1<=n && !visit[y][x+1]){
                        q.push(make_pair(y, x+1));
                        visit[y][x+1] = true;
                    }
                    if(arr[y-1][x] >= h && y-1 >= 1 && !visit[y-1][x]){
                        q.push(make_pair(y-1, x));
                        visit[y-1][x] = true;
                    }
                    if(arr[y][x-1] >= h && x-1 >= 1 && !visit[y][x-1]){
                        q.push(make_pair(y, x-1));
                        visit[y][x-1] = true;
                    }
                    q.pop();
                }
                tmpresult++;
            }
        }
    }
    result = max(result, tmpresult);
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=1;i<=100; i++){
        dfs(i);
        memset(visit, false, sizeof(visit));
    }
    cout<<result;
    return 0;
}