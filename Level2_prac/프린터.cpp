/** 문제설명 **/

/*
    인쇄 대기목록은 각각 우선순위를 가지고 있다.
    인쇄 순서가 되었더라도 자기보다 우선순위가 높은 문서가 있을 경우 뒤로 넘어간다.
    내가 요청한 문서의 현재 위치를 location으로 주어지고, 결과적으로 몇번째로 인쇄가 되는지 구하라.
*/

/** 솔루션 **/

/*
    우선순위 큐(최대 힙)와 pair를 원소로 가지는 큐를 이용할 것
*/



#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int len = priorities.size();
    int flag = 0;
    int temp;
    priority_queue<int> pq;
    
    queue<pair<int,int>> q;
    
    for(int i=0; i<len; i++){
        pq.push(priorities[i]);
        q.push(make_pair(priorities[i], i));
    }
    pair<int, int> n;
    int m;
    while(!q.empty()){
        n = q.front();
        m = pq.top();
        q.pop();
        
        if(m==n.first){
            pq.pop();
            if(n.second == location){
                return answer+1;
            }
            answer++;
        }
        else{
            q.push(n);
            
        }
        
    }
    
}