/** 솔루션 **/

/*
    1. h의 기준에 따라 경로가 바뀌므로 h에 대해 for 문을 돌려준다.

    2. 구역의 탐색 시작점을 찾기 위해 이중 for문을 사용하였고 방문하지 않았을 경우, 탐색을 시작한다.

    3. q가 빌 때까지 탐색을 하며 탐색이 끝나면 tmpresult를 1씩 올려준다.

    4. bfs 함수가 끝나는 시점에 result와 tmpresult의 최댒값을 result에 저장한다.
*/


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
int arr[101][101];
bool visit[101][101];
int result = 0;

void bfs(int h){
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
        bfs(i);
        memset(visit, false, sizeof(visit));
    }
    cout<<result;
    return 0;
}