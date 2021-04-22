#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[10];
int arr[10];
vector<int> result;
void dfs(int total, vector<int> v){
    
    if(v.size()==7){
        //cout<<total<<endl;
        if(total == 100){
            result = v;
            return;
        }

    }
    for(int i=1; i<=9; i++){
        if(!visit[i]){
            visit[i] = true;
            v.push_back(arr[i]);
            dfs(total+arr[i], v);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main(){
    vector<int> v;
    for(int i=1; i<=9; i++){
        scanf("%d", &arr[i]);
    }
    
    dfs(0, v);
    sort(result.begin(), result.end());
    for(auto i : result)
        cout<<i<<endl;
    return 0;
}