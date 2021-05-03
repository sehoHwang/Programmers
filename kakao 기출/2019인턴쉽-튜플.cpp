/** 솔루션 **/

/*
    1. '{' 또는 '}' 를 삭제 하였다.

    2. ','를 기준으로 존재하는 숫자에 대한 map을 사용하여 value 값을 증가시켰다.

    3. value가 많이 나타난 순서대로 answer에 push하였다.
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    int idx = 0;
    map<int, int> m;
    
    while(idx < s.length()){
        if(s[idx] == '{' || s[idx] == '}'){
            s.erase(idx, 1);
            idx--;
        }
        idx++;
    }
    int i=0;
    idx = 0;
    string tmp = "";
    while(idx < s.length()){
        
        if(s[idx] == ','){
            m[stoi(tmp)]++;
            tmp = "";
            i = idx = idx+1;
            continue;
        }
        tmp += s[idx];
        if(idx==s.length()-1){
            m[stoi(tmp)]++;
        }
        idx++;
    }
    
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);
    
    for(auto i : v){
        answer.push_back(i.first);
    }
    
    return answer;
}