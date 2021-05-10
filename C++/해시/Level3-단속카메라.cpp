/** 솔루션 **/

/*
    1. 우선순위 큐를 사용해 그리디 알고리즘을 구현하였다.

    2. routes를 오름차순 정렬하여, 진입 구간이 빠른 순으로 정렬된다.

    3. cur 변수를 사용해 cur < routes.size() || !pq.empty()인 동안
    
    - cur과 일치하는 모든 routes[i][0]을 큐에 삽입하고 idx를 1 증가시킨다.
    - 만약 큐가 비어있지 않고, 큐의 top (큐의 원소 중 가장 작은 값 -> 가장 이른 종료 시점)이 cur과 일치할 시, 전체 pop을 하고
    - answer를 1 증가시킨다.
    - 위 세 단계에 해당하지 않을 경우 cur만 증가시킨다.
*/


#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    sort(routes.begin(), routes.end());
    int idx = 0;
    int cur = routes[0][0];
    while(idx < routes.size() || !pq.empty()){
        while(idx < routes.size() && cur == routes[idx][0]){
            pq.push(routes[idx][1]);
            //cout<<"push : "<<routes[idx][1]<<endl;
            idx++;
        }
        if(!pq.empty() && cur == pq.top()){
            while(!pq.empty())
                pq.pop();
            answer++;
        }
        
        cur++;
    }
    return answer;
}