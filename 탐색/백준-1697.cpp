/** 솔루션 **/

/*
    1. bfs 문제

    2. queue<pair<int,int>> 자료형으로 해결했으며 first는 방문하는 지점, second는 현재까지의 이동 횟수를 저장한다.
*/


#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;
queue<pair<int, int>> q;
bool visit[100001];
int result = 0;

int main(){
    scanf("%d %d", &n, &k);
    int max_num = max(n, k);
    q.push(make_pair(n,0));

    while(!q.empty()){
        int num = q.front().first;
        int total = q.front().second;
        if(num==k){
            result = total;
            break;
        }
        q.pop();
        if(!visit[num]){
            visit[num] = true;
            if(num<=max_num+1)
                q.push(make_pair(num+1, total+1));
            if(num-1>=0)
                q.push(make_pair(num-1, total+1));
            if(num*2<=100000)
                q.push(make_pair(num*2, total+1));
        }
        
    }

    cout<<result;

    return 0;
}