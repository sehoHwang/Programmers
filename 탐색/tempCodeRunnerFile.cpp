#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int arr[101][101];
int visit[101];
int n;

int result = 0;

void dfs(int x){
    
    while(!s.empty()){
        int tmp = s.top();
        
        s.pop();
        if(visit[tmp] == 0){
            visit[tmp] = 1;
            
            if(tmp != 1)
                result++;
        
            for(int i=1; i<=n; i++){
                if(arr[tmp][i] == 1)
                    s.push(i);
            }   
        }
    }
}

int main(){
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        arr[r][c] = 1;
    }
    
    s.push(1);
    dfs(1);
    cout<<result;
    return 0;
}