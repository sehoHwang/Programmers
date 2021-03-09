/** 문제설명 **/

/*
    일차 선 다리를 트럭 여러 대가 가로지른다.
    트럭은 1초에 1만큼 움직이며, 다리는 무게 weight까지 견뎌내며, 길이는 birdge_length이다.
    트럭의 길이는 2이며 트럭이 다리에 완전히 진입하기 전까진 무게로 간주하지 않는다.
*/

/** 솔루션 **/

/*
    1. 다리에 진입한 트럭의 상황을 queue를 이용한다.
    2. queue의 크기가 다리의 길이와 같으면 pop을 해준다.
    3. 다음 트럭이 진입할 시에 트럭의 무게 합이 weight보다 작거나 같으면 push한다.
    4. push를 진행한 후 만약 더이상 진입할 트럭이 없다면 다리의 길이만큼을 answer에 더해준다.
    5. 만약 다음 트럭이 무게 초과로 진입을 하지 못한다면 0을 push한다.
*/

#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
   queue<int> q;
    int answer = 0;
    int total = 0;
    int i = 0;
    
    while(1){
        answer++;
        if(q.size() == bridge_length){
            total -= q.front();
            q.pop();
        }
        
        if(total + truck_weights[i] <= weight){
            if(i == truck_weights.size() - 1){
                answer += bridge_length;
                break;
            }
            
            q.push(truck_weights[i]);
            i++;
            total+=q.back();
        }
        else{
            q.push(0);
        }
    }
    
    return answer;
}

