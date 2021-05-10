/** 문제설명 **/

/*
    모든 음식의 스코빌 지수가 배열로 주어지고 모든 원소가 주어지는 K의 값보다 크게 만들어야 합니다.

    이를 위해 섞은 음식의 스코빌 지수 = 가장 지수가 낮은 음식의 스코빌 지수 + (가장 지수가 낮은 음식의 스코빌 지수 * 2)를 구해 다시 넣어줍니다.

    ex)
    새로운 음식의 스코빌 지수 = 1 + (2 * 2) = 5
    가진 음식의 스코빌 지수 = [5, 3, 9, 10, 12]

    단, K를 충족 못하는 경우에는 -1을 반환합니다.

*/

/** 솔루션 **/

/*
    최소힙을 사용하면 쉽게 해결할 수 있는 문제이지만 몇가지 경우의 수를 고려해야 한다.

    1. 힙의 사이즈가 2보다 작은 경우

    2. 힙의 사이즈가 2인 경우에 대한 스코빌 지수 확인을 while 루프 문 탈출 이후에도 해주어야 합니다.
*/



#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int flag = 0;
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i=0; i<scoville.size(); i++){
        q.push(scoville[i]);
    }
    int tmp1, tmp2, result, min;
    
    if(q.top() >= K){
        return 0;
    }
    
    while(q.size()>=2){
        min = q.top();
        if(min >= K){
            flag = 1;
            break;
        }
        tmp1 = q.top();
        q.pop();
        tmp2 = q.top();
        q.pop();
        result = tmp1 + (tmp2*2);
        q.push(result);
        answer++;
    }
    
    
    if(flag == 1){
        return answer;
    }
    
    else{
        if(q.top() >= K){
            return answer;
        }
        else
            return -1;
    }
}

/** 솔루션 **/

/*
    풀이가 동일했다.
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        return a>b;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int> ,compare> pq;    
    
    for(auto i : scoville){
        pq.push(i);
    }
    
    int min = pq.top();
    if(min >= K)
        return 0;
    
    while(!pq.empty()){
        
        int first = pq.top();
        if(pq.size()==1){
            if(first>=K){
                return answer;
            }   
            else
                return -1;
        }
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        if(first >=K)
            return answer;
        
        pq.push(first + second*2);
        answer++;
    }
    
    return answer;
}