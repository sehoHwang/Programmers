/** 솔루션 **/

/*
    1. unordered_map 자료구조를 사용해 "change" 명령어 시마다 value값 업데이트

    2. userid와 문장에 대한 벡터를 선언해 인덱스 별로 조회하며 map[userid]+sen 문자열을 answer에 삽입
*/


#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> parse;
unordered_map<string, string> m;

void split(string tmp){
    int s = 0;
    for(int i=0; i<tmp.length(); i++){
        if(tmp[i] == ' '){
            parse.push_back(tmp.substr(s, i-s));
            s = i+1;
        }
    }
    parse.push_back(tmp.substr(s));
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> id_loc;
    vector<string> sen;
    string inst, id, nick;
    for(auto i : record){
        split(i);
        inst = parse[0];
        id = parse[1];
        nick = parse[2];
        //cout<<"명령 : "<<inst<<" 아이디 : "<<id<<" 닉네임 : "<<nick<<endl;
        if(inst == "Enter"){
            m[id] = nick;
            id_loc.push_back(id);
            sen.push_back("님이 들어왔습니다.");
        }
        else if(inst == "Leave"){
            id_loc.push_back(id);
            sen.push_back("님이 나갔습니다.");
        }
        else{
            m[id] = nick;
        }
        parse.clear();
    }
    

    for(int i=0; i<sen.size(); i++){
        answer.push_back(m[id_loc[i]]+sen[i]);
    }
    
    return answer;
}