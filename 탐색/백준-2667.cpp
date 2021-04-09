/** 솔루션 **/

/*
    1. 네 가지 방향에 대한 dfs를 수행한다.

    2. 입력이 띄어쓰기가 없으므로 string으로 입력 받아야 한다.

    3. 이중 for문을 순회하며 방문하지 않은 지점일 경우 total=0으로 초기화하고 
    해당 지점에서의 탐색이 끝났을때의 total 값을 vector에 push한다.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string arr[26];
int visit[26][26];
int n;
int total = 0;
vector<int> v;

void dfs(int y, int x){
    visit[y][x] = 1;
    int rightx = x+1;
    int righty = y;
    int leftx = x-1;
    int lefty = y;
    int upx = x;
    int upy = y-1;
    int downx = x;
    int downy = y+1;
    total++;
    if(rightx>=1 && rightx<=n && righty>=1 && rightx<=n && visit[righty][rightx] == 0 && arr[righty][rightx-1] == '1'){
        dfs(righty, rightx);
    }
    if(leftx<=n && leftx>=1 && lefty<=n && lefty>=1 && visit[lefty][leftx] == 0 && arr[lefty][leftx-1] == '1'){
        dfs(lefty, leftx);
    }
    if(upy >=1 && upy<=n && upx<=n && upx>=1 && visit[upy][upx] == 0 && arr[upy][upx-1] == '1'){
        dfs(upy, upx);
    }
    if(downy<= n && downy>=1 && downx<=n && downx>=1 && visit[downy][downx] == 0 && arr[downy][downx-1]=='1'){
        dfs(downy, downx);
    }
    return;
}

int main(){
    int tmp;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    
    int count = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visit[i][j] == 0 && arr[i][j-1] == '1'){
                total = 0;
                count++;
                dfs(i,j);
                v.push_back(total);
            }
        }
    }

    cout<<count<<endl;
    sort(v.begin(), v.end());
    for(auto i : v){
        cout<<i<<endl;
    }

    return 0;
}