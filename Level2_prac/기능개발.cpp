/** 문제설명 **/

/*
    먼저 배포되어야 하는 작업의 진도가 적힌 배열 progresses, 
    각 작업의 개발 속도가 적힌 배열 speeds가 있다.
    각 배포마다 몇개의 기능이 배포되는지 구하라.
*/

/** 솔루션 **/

/*
    우선, 작업 별로 배포까지 걸리는 날짜를 구한다.
    초기에는 for 문과 while문으로 탐색해 구하려고 했으나 계속해서 테스트 케이스에서 실패했다.

    그러다 queue를 사용해 조건이 맞는동안 데이터를 축적을 시키고 조건이 맞지 않을때 queue의 사이즈를 answer에 push하고
    비우고 이를 반복하는 방법을 생각해 내었다.
*/



#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    vector<int> dDay;
    int len = progresses.size();
    int tmp;
    for(int i=0; i<len; i++){
        tmp = 100-progresses[i];
        if(tmp%speeds[i]==0){
            dDay.push_back(tmp/speeds[i]);
        }
        else{
            dDay.push_back(tmp/speeds[i] + 1);
        }
    }
    
    q.push(dDay[0]);
    for(int i=1; i<dDay.size(); i++){
        if(q.front() >= dDay[i]){
            q.push(dDay[i]);
        }
        else{
            answer.push_back(q.size());
            while(!q.empty()) q.pop();
            q.push(dDay[i]);
        }
        
    }
    answer.push_back(q.size());
    return answer;
}