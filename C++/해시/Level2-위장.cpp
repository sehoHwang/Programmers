/** 솔루션 **/

/*
    1. map<string, int> 자료구조를 사용

    2. map에 clothes의 종류가 없으면 pair(clothes 종류, 1)을 삽입

    3. 종류가 있으면 map의 해당 clothes 종류에 대해 second 값을 1 증가

    4. 각 clothes 종류에 대해 안입는 경우를 고려해 +1씩해서 곱한 후 모든 옷을 안입을 경우 1을 빼줌
*/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    for(auto i : clothes){
        if(m.find(i[1])==m.end()){
            
            m.insert(make_pair(i[1], 1));
        }
        else{
            m.find(i[1])->second++;
        }
    }
    
    for(auto i : m){
        answer*= (i.second+1);
    }
    return answer-1;
}