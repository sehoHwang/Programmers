/** 솔루션 **/

/*
    1. dfs를 사용하였다.

    2. 변환할 수 있는 단어인지 판별하는 함수 possible을 구현하였다.

    3. 변환이 가능한지 기준이 되는 단어가 계속 바뀌므로 next라는 string 변수에 할당하였다.

    4. for문을 돌 때, erase를 할 시 iterator에 문제가 생기므로 변환이 가능한 경우 tmpstr 벡터를 생성하고 여기서 erase 작업을 한 후
    다음 dfs 매개변수로 넘겨주었다.
    
*/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int result = 1000001;
string s, e;
int len;

bool possible(string cur, string tmp){
    int count=0;
    for(int i=0; i<len; i++){
        if(cur[i] == tmp[i])
            count++;
    }
    if(count==len-1)
        return true;
    return false;
}

void dfs(string cur, vector<string> words, int total){
    string next;
    for(int i=0; i<words.size(); i++){
        if(possible(cur, words[i])){                           
            vector<string> tmpstr = words;
            
            next = words[i];

            if(words[i] == e && total+1<result){
                result = total+1;
                return;
            }
            tmpstr.erase(tmpstr.begin()+i);
            
            dfs(next, tmpstr, total+1);
        }
    }
    if(words.size()==0)
        return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    s = begin;
    e = target;
    len = s.length();
    auto it = find(words.begin(), words.end(), e);
    if(it==words.end())
        return 0;
    
    dfs(s, words, 0);
    
    return result;
}