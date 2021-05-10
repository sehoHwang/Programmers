/** 솔루션 **/

/*
    1. 사용자 아이디인 user_id와 제재 아이디인 banned_id가 주어진다. banned_id를 확인하여 가능한 user_id의 경우의 수를 구하는 문제이다.

    2. dfs를 사용하였으며 매개변수 idx가 banned_id의 길이와 같아지면 종료가 되는데 이 때,

       해당 dfs에 대해 visit을 한 단어들을 합쳐 <set> 자료구조에 넣는다. (set을 통해 중복 처리)

    3. 해당 user_id와 banned_id가 일치할 수 있는 경우 백트래킹을 사용해 dfs(idx+1)을 통해 탐색해 나간다. (visit 사용)
*/


#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
vector<string> user;
vector<string> banned;
set<string> s;
bool visit[9];

void dfs(int idx){
    if(idx == banned.size()){
        string tmp = "";
        for(int i=0;i<user.size(); i++){
            if(visit[i]){
                tmp += user[i];
            }
        }
        s.insert(tmp);
        return;
    }
    
    for(int i=0; i<user.size(); i++){
        bool isAble = true;
        
        if(visit[i]){
            continue;
        }
        
        if(user[i].length() != banned[idx].length()){
            continue;
        }
        
        for(int j=0; j<user[i].length(); j++){
            if(banned[idx][j] == '*')
                continue;
            
            if(banned[idx][j] != user[i][j]){
                isAble = false;
                break;
            }
        }
        if(isAble){
            visit[i] = true;
            dfs(idx + 1);
            visit[i] = false;
        }
    }
    return;
}
 
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    user = user_id;
    banned = banned_id;
    
    dfs(0);
    answer = s.size();
    return answer;
}