#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct VectorStruct{
    int left;
    int right;
    int dis;
};

struct input{
    int left;
    int right;
    int x;
};

struct compare{
    bool operator () (VectorStruct a, VectorStruct b){
        return a.dis > b.dis;
    }
};

bool flag[100001];
input in[100002];

int main(){
    int n, k, s;
    int tmp;
    int answer = 0;
    
    vector<int> v;
    vector<int> result;
    VectorStruct vectorStruct;
    vector<VectorStruct> info;
    priority_queue <VectorStruct, vector<VectorStruct>, compare> pq;
    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &s);
        in[i].x = s;
        in[i].left = i-1;
        in[i].right = i+1;
    }

    for(int i=1; i<n; i++){
        vectorStruct.left = i;
        vectorStruct.right = i+1;
        vectorStruct.dis = in[i+1].x - in[i].x;
        pq.push(vectorStruct);
    }

    while(k--){
        VectorStruct tmp = pq.top();
        int left = tmp.left;
        int right = tmp.right;
        
        pq.pop();
        if(flag[left] || flag[right]){
            k++;
            continue;
        }
        flag[left] = true;
        flag[right] = true;
        answer += tmp.dis;
        //cout<<answer<<endl;
        int nextLeft = in[left].left;
        int nextRight = in[right].right;
        
        tmp.left = nextLeft;
        tmp.right = nextRight;
        tmp.dis = in[nextRight].x - in[nextLeft].x - tmp.dis-1;
        //cout<<tmp.dis<<endl;
        pq.push(tmp);

    }

    cout<<answer;
    
    
}