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

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
 
int n, k;
int d[100001];
 
int main() {
    scanf("%d %d", &n, &k);
 
    //동생<수빈 일경우 갈수있는 방법이 무조건 '현재-1'일거라 생각
    if (n > k) { 
        printf("%d\n", n - k);
        return 0;
    }
    
    d[n] = 0;    //시작은 0초
    
    if (n == 0)
        d[n + 1] = 1;    //음수는 생각하지 않음
    else
        d[n - 1] = d[n + 1] = 1;
 
    
    for (int i = n + 2; i <= k + 1; i++) {
        
        if (i % 2 == 0)
            d[i] = min(d[i - 1] + 1, d[i / 2] + 1);
        else    
            d[i] = d[i - 1] + 1;
 
        d[i - 1] = min(d[i - 1], d[i] + 1);
    }
 
    printf("%d\n", d[k]);
 
    return 0;
}

*/
