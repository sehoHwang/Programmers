/** 문제설명 **/

/*
    skill : 선행 스킬 순서
    
    skill_trees : 매개변수로 주어지는 사용자가 희망하는 스킬 트리

    주어진 skill_trees 목록 중에 선행 스킬 순서를 지키는 갯수를 반환할 것
*/

/** 솔루션 **/

/*
    -vector<string> 변수 result를 선언
    
    -각 skill_trees 마다 skill에 포함된 문자로만 이루어진 문자열을 result에 push

    -result의 요소들을  skill과 비교해가며 스킬 순서를 어길 경우 flag에 1을 주어 구분
*/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<string> result;
    
    for(int i=0; i<skill_trees.size(); i++){
        string tmp = "";
        for(int j=0; j<skill_trees[i].size(); j++){
            char temp = skill_trees[i][j];
            auto it = skill.find(temp);
            if(it==-1){
                continue;
            }
            else
                tmp+=temp;
        }
        result.push_back(tmp);
    }    
    
    for(int i=0; i<result.size(); i++){
        int flag = 0;
        for(int j=0; j<result[i].size(); j++){
            if(skill[j] != result[i][j]){
                flag = 1;
            }
        }
        if(flag==0)
            answer++;
    }
    
    return answer;
}

/** 솔루션 **/

/*
    1. 각 문자열에 대한 1차 for 문

    2. 각 문자열을 이루는 문자에 대해 2차 for 문을 돌리는데, skill에 포함돼있는지 find 함수를 통해 찾는다.
    
    3. idx 변수를 선언해 발견할 시 증가

    4. 만약 idx와 find의 return 인덱스가 다를 경우 flag 변수 = 1

    5. flag == 0 이면 answer 추가
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len = skill.length();
    for(auto i : skill_trees){
        int idx = 0;
        int flag = 0;
        for(int j=0; j<i.length(); j++){
            auto it = skill.find(i[j]);
            if(it>=0 && it <=skill.length()-1){
                if(idx == it){
                    idx++;
                }
                else{
                    flag = 1;
                }
            }
        }
        if(flag == 0)
            answer++;
    }
    
    return answer;
}