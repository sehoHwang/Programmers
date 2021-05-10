/** 솔루션 **/

/*
    1. 우선순위 큐를 두개 생성하여 해결하였다.
    
    2. pq1을 최대 힙, pq2를 최소 힙으로 생성 후 
    
    최댓값 삭제의 경우, pq1에서 삭제하였고, 최솟값 삭제의 경우 pq2를 삭제하였다.

    3. pq1을 vector에 모두 담고 pq2를 하나씩 꺼내며 vector에 해당 원소가 존재할 경우에 vector tmp2에 삽입하였다.

    4. tmp2의 크기가 0이거나 1이면 {0,0}을 반환 아니면 최댓값과 최솟값을 구해 반환하였다.
*/


#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        return a > b;
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> tmp;
    vector<int> tmp2;
    priority_queue<int, vector<int>> pq1;
    priority_queue<int, vector<int>, compare> pq2;
    
    for(int i=0; i<operations.size(); i++){
        int len = operations[i].length();
        auto it = operations[i].find(" ");
        string action = operations[i].substr(0, it);
        string number = operations[i].substr(it+1, len-it);
        int num = stoi(number);
        //cout<<action<<endl;
        if(action == "I"){
            pq1.push(num);
            pq2.push(num);
        } else{
            if(num == -1){
                if(!pq2.empty())
                    pq2.pop();
            } else{
                if(!pq1.empty())
                    pq1.pop();
            }
        }
    }
    
    while(!pq1.empty()){
        tmp.push_back(pq1.top());
        pq1.pop();
    }
    
    while(!pq2.empty()){
        auto it = find(tmp.begin(), tmp.end(), pq2.top());
        if(it!=tmp.end())
            tmp2.push_back(pq2.top());
        pq2.pop();
    }
    if(tmp2.size()==0 || tmp2.size()==1){
        return {0,0};
    }
    int first = tmp2[0];
    int second = tmp2[0];
    for(int i=1; i<tmp2.size(); i++){
        first = max(first, tmp2[i]);
        second = min(second, tmp2[i]);
    }
    return {first, second};
}

/** 솔루션 **/

/*
    1. multiset을 이용해 코드 수를 어마어마하게 줄였다.

    2. 포인터를 통해 multiset.begin()과 multiset.end()에 접근하여 key를 줄여 나갔다.
*/


#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    for(auto i : operations){
        if(i=="D 1" && ms.size()>0){
            ms.erase(--ms.end());
        } else if(i=="D -1" && ms.size()>0){
            ms.erase(ms.begin());
        } else{
            int num = stoi(i.substr(2, i.size()-2));
            ms.insert(num);
        }
    }
    
    if(ms.size() == 0 || ms.size()==1)
        return {0,0};
    
    return {*(--ms.end()), *ms.begin()};
    
}