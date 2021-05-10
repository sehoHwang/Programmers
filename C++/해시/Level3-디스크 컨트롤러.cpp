/** 솔루션 **/

/*
    1. jobs vector를 우선 요청 시간 순서대로 정렬을 한다. (큐의 삽입 작업이 일어날 때 마다 j인덱스 증가)

    2. while문을 돌며 현재 시각에 요청할 수 있는 작업들 중 소요시간이 가장 짧은 것부터 처리해야 한다. (우선순위 큐 사용)

    3. 현재 time에서 요청할 수 있는 작업들은 큐에 넣고 continue를 돌린다.

    4. 만약 넣을게 없고, 큐에 원소들이 존재하면 연산을 한 후 time을 늘린다. time이 늘어났으므로 다시 첫번째 if문을 통해 현재
    
    시각에서 처리할 수 있는 작업에 대해 3번 작업을 해준다.

    5. 만약 넣을게 없고, 큐 또한 비어 있다면, 현재 시각에 처리할 수 있는 작업이 없는 것이므로 jobs[j] 인덱스의 요청시간을
    
    time으로 설정하고 위 작업을 반복한다.
*/


#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }  
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq; 
    
    sort(jobs.begin(), jobs.end());
    
    int j = 0;
    while(!pq.empty() || jobs.size() > j){
        
        if(j<jobs.size() && time >= jobs[j][0]){
            vector<int> tmp;
            tmp.push_back(jobs[j][0]);
            tmp.push_back(jobs[j][1]);
            pq.push(tmp);
            j++;
            continue;
        }
        
        if(!pq.empty()){
            time+=pq.top()[1];
            answer += (time - pq.top()[0]);
            pq.pop();
        }
        else{
            time = jobs[j][0];
        }
    }
    
    return answer/jobs.size();
}