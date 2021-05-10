/** 솔루션 **/

/*
    1. 문제를 잘 읽고 각 분기 조건에 대해 재귀 함수를 잘 사용하면 된다.

    - 균형 문자열인지 확인해주는 함수

    - 올바른 문자열인지 확인해주는 함수 
    
    - 과정에 따라 문자열을 변환하는 함수

    -> 총 3개를 구현하였다.
*/


#include <string>
#include <vector>
#include <iostream>

using namespace std;

string u;
string v;

bool isBalanced(string s){
    char first = s[0];
    int idx = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == first)
            idx++;
        else
            idx--;
    }
    if(idx == 0)
        return true;
    return false;
}

bool isRight(string s){
    char tmp = '(';
    int idx = 0;
    for(int i=0; i<s.length(); i++){
        if(idx==0 && s[i]==')')
            return false;
        if(s[i] == tmp)
            idx++;
        else
            idx--;   
    }
    return true;
}

string translation(string p){
    if(p==""){
        return "";
    }
    int len = p.length();
    int idx=1;
    char firstP = p[0];
    string tmp=to_string(p[0]);
    for(int i=1; i<len; i++){
        if(p[i]!=firstP){
            idx--;
        }
        else{
            idx++;
        }
        if(idx==0){
            u = p.substr(0,i+1);
            v = p.substr(i+1, len-i-1);
            break;
        }
    }
    string temp = u;
    
    if(isRight(u)){
        temp+=translation(v);
    }
    
    else{
        string emp = "(";
        emp+=translation(v)+")";
        
        string sumstr="";
        
        temp = temp.substr(1, temp.length()-2);
        for(int i=0; i<temp.length(); i++){
            if(temp[i]=='(')
                temp[i]=')';
            else
                temp[i]='(';
        }
        
        return emp+=temp;
    }
    
    return temp;
}

string solution(string p) {
    string answer = "";
    
    answer = translation(p);
    
    
    return answer;
}